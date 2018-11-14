#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <time.h>

#include "bip39.h"
#include "bip32.h"

sqlite3 *diskDB = NULL;
sqlite3 *memDB = NULL;
sqlite3_stmt *insert = NULL;
char *errmsg = NULL;

void close() {
    sqlite3_finalize(insert);
    sqlite3_close(diskDB);
    sqlite3_close(memDB);
    sqlite3_free(errmsg);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the database name.\n");
        exit(1);
    }

    if (sqlite3_open(":memory:", &memDB) != SQLITE_OK) {
        printf("Error opening memory database\n");
        exit(1);
    }

    if (sqlite3_exec(memDB, "CREATE TABLE IF NOT EXISTS vul (mnemonic TEXT NOT NULL, address BLOB NOT NULL)", NULL, NULL, &errmsg) != SQLITE_OK) {
        printf("Error creating table %s\n", errmsg);
        close();
        exit(1);
    }

    if (sqlite3_exec(memDB, "CREATE UNIQUE INDEX IF NOT EXISTS idx_mnemonic ON vul(mnemonic)", NULL, NULL, &errmsg) != SQLITE_OK) {
        printf("Error creating index %s\n", errmsg);
        close();
        exit(1);
    }

    if (sqlite3_exec(memDB, "CREATE UNIQUE INDEX IF NOT EXISTS idx_address ON vul(address)", NULL, NULL, &errmsg) != SQLITE_OK) {
        printf("Error creating index %s\n", errmsg);
        close();
        exit(1);
    }

    if (sqlite3_prepare_v2(memDB, "INSERT OR IGNORE INTO vul(mnemonic, address) VALUES(?,?)", -1, &insert, NULL) != SQLITE_OK) {
        printf("Error creating index %s\n", errmsg);
        close();
        exit(1);
    }

    clock_t startTime = clock();

    int start = 1533081600;
    int end = 1535760000;

    int result;
    uint8_t seed[512/8];
    HDNode node;
    uint8_t pubkey[20];

	for (int i = start; i < end; i++) {
        srand(i);

		const char *mnemonic = mnemonic_generate(128);
		mnemonic = mnemonic_generate(128);
		mnemonic_to_seed(mnemonic, "", seed, NULL);

		hdnode_from_seed(seed, 512/8, "secp256k1", &node);
		hdnode_private_ckd(&node, 44|0x80000000);
		hdnode_private_ckd(&node, 60|0x80000000);
		hdnode_private_ckd(&node, 0|0x80000000);
		hdnode_private_ckd(&node, 0);
		hdnode_private_ckd(&node, 0);

		hdnode_get_ethereum_pubkeyhash(&node, pubkey);

        result = sqlite3_bind_text(insert, 1, mnemonic, -1, SQLITE_STATIC);
        if (result != SQLITE_OK) {
            printf("Can't bind menmonic: %d\n", result);
            close();
            exit(1);
        }

        result = sqlite3_bind_blob(insert, 2, pubkey, 20, SQLITE_STATIC);
        if (result != SQLITE_OK) {
            printf("Can't bind pubkey: %d\n", result);
            close();
            exit(1);
        }

        result = sqlite3_step(insert);
        if (result != SQLITE_DONE) {
			fprintf(stderr, "Can't insert: %d.\n", result);
            close();
			exit(1);
		}

        sqlite3_reset(insert);
	}

    clock_t endTime = clock();
    double cpu_time_used = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
	printf("Completed in %gs\n", cpu_time_used);

    if (sqlite3_open(argv[1], &diskDB) != SQLITE_OK) {
        printf("Error opening %s\n", argv[1]);
        close();
        exit(1);
    }

    sqlite3_backup *backup = sqlite3_backup_init(diskDB, "main", memDB, "main");
    if (backup == NULL) {
        printf("Error intializing backup\n");
        close();
        exit(1);
    }
    if (sqlite3_backup_step(backup, -1) != SQLITE_DONE) {
        printf("Error intializing backup\n");
        close();
        exit(1);
    }
    sqlite3_backup_finish(backup);

    close();

    return 0;
}

     
     
     