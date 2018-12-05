#include <TrustWalletCore/TWData.h>
#include <TrustWalletCore/TWString.h>

#define WRAP(type, x) std::shared_ptr<type>(x, type##Delete)
#define WRAPD(x) std::shared_ptr<TWData>(x, TWDataDelete)
#define WRAPS(x) std::shared_ptr<TWString>(x, TWStringDelete)
#define STRING(x) std::shared_ptr<TWString>(TWStringCreateWithUTF8Bytes(x), TWStringDelete)
#define DATA(x) std::shared_ptr<TWData>(TWDataCreateWithHexString(STRING(x).get()), TWDataDelete)
