import * as $protobuf from "protobufjs";
/** Namespace TW. */
export namespace TW {

    /** Namespace proto. */
    namespace proto {

        /** Properties of a Result. */
        interface IResult {

            /** Result success */
            success?: (boolean|null);

            /** Result error */
            error?: (string|null);

            /** Result objects */
            objects?: (google.protobuf.IAny[]|null);
        }

        /** Represents a Result. */
        class Result implements IResult {

            /**
             * Constructs a new Result.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IResult);

            /** Result success. */
            public success: boolean;

            /** Result error. */
            public error: string;

            /** Result objects. */
            public objects: google.protobuf.IAny[];

            /**
             * Creates a new Result instance using the specified properties.
             * @param [properties] Properties to set
             * @returns Result instance
             */
            public static create(properties?: TW.proto.IResult): TW.proto.Result;

            /**
             * Encodes the specified Result message. Does not implicitly {@link TW.proto.Result.verify|verify} messages.
             * @param message Result message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IResult, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified Result message, length delimited. Does not implicitly {@link TW.proto.Result.verify|verify} messages.
             * @param message Result message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IResult, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a Result message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns Result
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.Result;

            /**
             * Decodes a Result message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns Result
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.Result;

            /**
             * Verifies a Result message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a Result message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns Result
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.Result;

            /**
             * Creates a plain object from a Result message. Also converts values to other types if specified.
             * @param message Result
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.Result, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this Result to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinTransaction. */
        interface IBitcoinTransaction {

            /** BitcoinTransaction version */
            version?: (number|null);

            /** BitcoinTransaction lockTime */
            lockTime?: (number|null);

            /** BitcoinTransaction inputs */
            inputs?: (TW.proto.IBitcoinTransactionInput[]|null);

            /** BitcoinTransaction outputs */
            outputs?: (TW.proto.IBitcoinTransactionOutput[]|null);
        }

        /** Represents a BitcoinTransaction. */
        class BitcoinTransaction implements IBitcoinTransaction {

            /**
             * Constructs a new BitcoinTransaction.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinTransaction);

            /** BitcoinTransaction version. */
            public version: number;

            /** BitcoinTransaction lockTime. */
            public lockTime: number;

            /** BitcoinTransaction inputs. */
            public inputs: TW.proto.IBitcoinTransactionInput[];

            /** BitcoinTransaction outputs. */
            public outputs: TW.proto.IBitcoinTransactionOutput[];

            /**
             * Creates a new BitcoinTransaction instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinTransaction instance
             */
            public static create(properties?: TW.proto.IBitcoinTransaction): TW.proto.BitcoinTransaction;

            /**
             * Encodes the specified BitcoinTransaction message. Does not implicitly {@link TW.proto.BitcoinTransaction.verify|verify} messages.
             * @param message BitcoinTransaction message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinTransaction, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinTransaction message, length delimited. Does not implicitly {@link TW.proto.BitcoinTransaction.verify|verify} messages.
             * @param message BitcoinTransaction message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinTransaction, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinTransaction message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinTransaction
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinTransaction;

            /**
             * Decodes a BitcoinTransaction message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinTransaction
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinTransaction;

            /**
             * Verifies a BitcoinTransaction message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinTransaction message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinTransaction
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinTransaction;

            /**
             * Creates a plain object from a BitcoinTransaction message. Also converts values to other types if specified.
             * @param message BitcoinTransaction
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinTransaction, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinTransaction to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinTransactionInput. */
        interface IBitcoinTransactionInput {

            /** BitcoinTransactionInput previousOutput */
            previousOutput?: (TW.proto.IBitcoinOutPoint|null);

            /** BitcoinTransactionInput sequence */
            sequence?: (number|null);

            /** BitcoinTransactionInput script */
            script?: (Uint8Array|null);
        }

        /** Represents a BitcoinTransactionInput. */
        class BitcoinTransactionInput implements IBitcoinTransactionInput {

            /**
             * Constructs a new BitcoinTransactionInput.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinTransactionInput);

            /** BitcoinTransactionInput previousOutput. */
            public previousOutput?: (TW.proto.IBitcoinOutPoint|null);

            /** BitcoinTransactionInput sequence. */
            public sequence: number;

            /** BitcoinTransactionInput script. */
            public script: Uint8Array;

            /**
             * Creates a new BitcoinTransactionInput instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinTransactionInput instance
             */
            public static create(properties?: TW.proto.IBitcoinTransactionInput): TW.proto.BitcoinTransactionInput;

            /**
             * Encodes the specified BitcoinTransactionInput message. Does not implicitly {@link TW.proto.BitcoinTransactionInput.verify|verify} messages.
             * @param message BitcoinTransactionInput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinTransactionInput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinTransactionInput message, length delimited. Does not implicitly {@link TW.proto.BitcoinTransactionInput.verify|verify} messages.
             * @param message BitcoinTransactionInput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinTransactionInput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinTransactionInput message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinTransactionInput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinTransactionInput;

            /**
             * Decodes a BitcoinTransactionInput message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinTransactionInput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinTransactionInput;

            /**
             * Verifies a BitcoinTransactionInput message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinTransactionInput message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinTransactionInput
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinTransactionInput;

            /**
             * Creates a plain object from a BitcoinTransactionInput message. Also converts values to other types if specified.
             * @param message BitcoinTransactionInput
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinTransactionInput, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinTransactionInput to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinOutPoint. */
        interface IBitcoinOutPoint {

            /** BitcoinOutPoint hash */
            hash?: (Uint8Array|null);

            /** BitcoinOutPoint index */
            index?: (number|null);

            /** BitcoinOutPoint sequence */
            sequence?: (number|null);
        }

        /** Represents a BitcoinOutPoint. */
        class BitcoinOutPoint implements IBitcoinOutPoint {

            /**
             * Constructs a new BitcoinOutPoint.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinOutPoint);

            /** BitcoinOutPoint hash. */
            public hash: Uint8Array;

            /** BitcoinOutPoint index. */
            public index: number;

            /** BitcoinOutPoint sequence. */
            public sequence: number;

            /**
             * Creates a new BitcoinOutPoint instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinOutPoint instance
             */
            public static create(properties?: TW.proto.IBitcoinOutPoint): TW.proto.BitcoinOutPoint;

            /**
             * Encodes the specified BitcoinOutPoint message. Does not implicitly {@link TW.proto.BitcoinOutPoint.verify|verify} messages.
             * @param message BitcoinOutPoint message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinOutPoint, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinOutPoint message, length delimited. Does not implicitly {@link TW.proto.BitcoinOutPoint.verify|verify} messages.
             * @param message BitcoinOutPoint message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinOutPoint, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinOutPoint message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinOutPoint
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinOutPoint;

            /**
             * Decodes a BitcoinOutPoint message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinOutPoint
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinOutPoint;

            /**
             * Verifies a BitcoinOutPoint message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinOutPoint message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinOutPoint
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinOutPoint;

            /**
             * Creates a plain object from a BitcoinOutPoint message. Also converts values to other types if specified.
             * @param message BitcoinOutPoint
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinOutPoint, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinOutPoint to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinTransactionOutput. */
        interface IBitcoinTransactionOutput {

            /** BitcoinTransactionOutput value */
            value?: (Long|null);

            /** BitcoinTransactionOutput script */
            script?: (Uint8Array|null);
        }

        /** Represents a BitcoinTransactionOutput. */
        class BitcoinTransactionOutput implements IBitcoinTransactionOutput {

            /**
             * Constructs a new BitcoinTransactionOutput.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinTransactionOutput);

            /** BitcoinTransactionOutput value. */
            public value: Long;

            /** BitcoinTransactionOutput script. */
            public script: Uint8Array;

            /**
             * Creates a new BitcoinTransactionOutput instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinTransactionOutput instance
             */
            public static create(properties?: TW.proto.IBitcoinTransactionOutput): TW.proto.BitcoinTransactionOutput;

            /**
             * Encodes the specified BitcoinTransactionOutput message. Does not implicitly {@link TW.proto.BitcoinTransactionOutput.verify|verify} messages.
             * @param message BitcoinTransactionOutput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinTransactionOutput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinTransactionOutput message, length delimited. Does not implicitly {@link TW.proto.BitcoinTransactionOutput.verify|verify} messages.
             * @param message BitcoinTransactionOutput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinTransactionOutput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinTransactionOutput message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinTransactionOutput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinTransactionOutput;

            /**
             * Decodes a BitcoinTransactionOutput message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinTransactionOutput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinTransactionOutput;

            /**
             * Verifies a BitcoinTransactionOutput message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinTransactionOutput message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinTransactionOutput
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinTransactionOutput;

            /**
             * Creates a plain object from a BitcoinTransactionOutput message. Also converts values to other types if specified.
             * @param message BitcoinTransactionOutput
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinTransactionOutput, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinTransactionOutput to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinUnspentTransaction. */
        interface IBitcoinUnspentTransaction {

            /** BitcoinUnspentTransaction outPoint */
            outPoint?: (TW.proto.IBitcoinOutPoint|null);

            /** BitcoinUnspentTransaction script */
            script?: (Uint8Array|null);

            /** BitcoinUnspentTransaction amount */
            amount?: (Long|null);
        }

        /** Represents a BitcoinUnspentTransaction. */
        class BitcoinUnspentTransaction implements IBitcoinUnspentTransaction {

            /**
             * Constructs a new BitcoinUnspentTransaction.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinUnspentTransaction);

            /** BitcoinUnspentTransaction outPoint. */
            public outPoint?: (TW.proto.IBitcoinOutPoint|null);

            /** BitcoinUnspentTransaction script. */
            public script: Uint8Array;

            /** BitcoinUnspentTransaction amount. */
            public amount: Long;

            /**
             * Creates a new BitcoinUnspentTransaction instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinUnspentTransaction instance
             */
            public static create(properties?: TW.proto.IBitcoinUnspentTransaction): TW.proto.BitcoinUnspentTransaction;

            /**
             * Encodes the specified BitcoinUnspentTransaction message. Does not implicitly {@link TW.proto.BitcoinUnspentTransaction.verify|verify} messages.
             * @param message BitcoinUnspentTransaction message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinUnspentTransaction, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinUnspentTransaction message, length delimited. Does not implicitly {@link TW.proto.BitcoinUnspentTransaction.verify|verify} messages.
             * @param message BitcoinUnspentTransaction message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinUnspentTransaction, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinUnspentTransaction message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinUnspentTransaction
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinUnspentTransaction;

            /**
             * Decodes a BitcoinUnspentTransaction message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinUnspentTransaction
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinUnspentTransaction;

            /**
             * Verifies a BitcoinUnspentTransaction message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinUnspentTransaction message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinUnspentTransaction
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinUnspentTransaction;

            /**
             * Creates a plain object from a BitcoinUnspentTransaction message. Also converts values to other types if specified.
             * @param message BitcoinUnspentTransaction
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinUnspentTransaction, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinUnspentTransaction to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinSigningInput. */
        interface IBitcoinSigningInput {

            /** BitcoinSigningInput hashType */
            hashType?: (number|null);

            /** BitcoinSigningInput amount */
            amount?: (Long|null);

            /** BitcoinSigningInput byteFee */
            byteFee?: (Long|null);

            /** BitcoinSigningInput toAddress */
            toAddress?: (string|null);

            /** BitcoinSigningInput changeAddress */
            changeAddress?: (string|null);

            /** BitcoinSigningInput privateKey */
            privateKey?: (Uint8Array[]|null);

            /** BitcoinSigningInput scripts */
            scripts?: ({ [k: string]: Uint8Array }|null);

            /** BitcoinSigningInput utxo */
            utxo?: (TW.proto.IBitcoinUnspentTransaction[]|null);
        }

        /** Represents a BitcoinSigningInput. */
        class BitcoinSigningInput implements IBitcoinSigningInput {

            /**
             * Constructs a new BitcoinSigningInput.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinSigningInput);

            /** BitcoinSigningInput hashType. */
            public hashType: number;

            /** BitcoinSigningInput amount. */
            public amount: Long;

            /** BitcoinSigningInput byteFee. */
            public byteFee: Long;

            /** BitcoinSigningInput toAddress. */
            public toAddress: string;

            /** BitcoinSigningInput changeAddress. */
            public changeAddress: string;

            /** BitcoinSigningInput privateKey. */
            public privateKey: Uint8Array[];

            /** BitcoinSigningInput scripts. */
            public scripts: { [k: string]: Uint8Array };

            /** BitcoinSigningInput utxo. */
            public utxo: TW.proto.IBitcoinUnspentTransaction[];

            /**
             * Creates a new BitcoinSigningInput instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinSigningInput instance
             */
            public static create(properties?: TW.proto.IBitcoinSigningInput): TW.proto.BitcoinSigningInput;

            /**
             * Encodes the specified BitcoinSigningInput message. Does not implicitly {@link TW.proto.BitcoinSigningInput.verify|verify} messages.
             * @param message BitcoinSigningInput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinSigningInput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinSigningInput message, length delimited. Does not implicitly {@link TW.proto.BitcoinSigningInput.verify|verify} messages.
             * @param message BitcoinSigningInput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinSigningInput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinSigningInput message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinSigningInput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinSigningInput;

            /**
             * Decodes a BitcoinSigningInput message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinSigningInput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinSigningInput;

            /**
             * Verifies a BitcoinSigningInput message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinSigningInput message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinSigningInput
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinSigningInput;

            /**
             * Creates a plain object from a BitcoinSigningInput message. Also converts values to other types if specified.
             * @param message BitcoinSigningInput
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinSigningInput, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinSigningInput to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BitcoinSigningOutput. */
        interface IBitcoinSigningOutput {

            /** BitcoinSigningOutput transaction */
            transaction?: (TW.proto.IBitcoinTransaction|null);

            /** BitcoinSigningOutput encoded */
            encoded?: (Uint8Array|null);
        }

        /** Represents a BitcoinSigningOutput. */
        class BitcoinSigningOutput implements IBitcoinSigningOutput {

            /**
             * Constructs a new BitcoinSigningOutput.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBitcoinSigningOutput);

            /** BitcoinSigningOutput transaction. */
            public transaction?: (TW.proto.IBitcoinTransaction|null);

            /** BitcoinSigningOutput encoded. */
            public encoded: Uint8Array;

            /**
             * Creates a new BitcoinSigningOutput instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BitcoinSigningOutput instance
             */
            public static create(properties?: TW.proto.IBitcoinSigningOutput): TW.proto.BitcoinSigningOutput;

            /**
             * Encodes the specified BitcoinSigningOutput message. Does not implicitly {@link TW.proto.BitcoinSigningOutput.verify|verify} messages.
             * @param message BitcoinSigningOutput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBitcoinSigningOutput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BitcoinSigningOutput message, length delimited. Does not implicitly {@link TW.proto.BitcoinSigningOutput.verify|verify} messages.
             * @param message BitcoinSigningOutput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBitcoinSigningOutput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BitcoinSigningOutput message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BitcoinSigningOutput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BitcoinSigningOutput;

            /**
             * Decodes a BitcoinSigningOutput message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BitcoinSigningOutput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BitcoinSigningOutput;

            /**
             * Verifies a BitcoinSigningOutput message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BitcoinSigningOutput message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BitcoinSigningOutput
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BitcoinSigningOutput;

            /**
             * Creates a plain object from a BitcoinSigningOutput message. Also converts values to other types if specified.
             * @param message BitcoinSigningOutput
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BitcoinSigningOutput, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BitcoinSigningOutput to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BinanceTransaction. */
        interface IBinanceTransaction {

            /** BinanceTransaction msgs */
            msgs?: (Uint8Array[]|null);

            /** BinanceTransaction signatures */
            signatures?: (Uint8Array[]|null);

            /** BinanceTransaction memo */
            memo?: (string|null);

            /** BinanceTransaction source */
            source?: (Long|null);

            /** BinanceTransaction data */
            data?: (Uint8Array|null);
        }

        /** Represents a BinanceTransaction. */
        class BinanceTransaction implements IBinanceTransaction {

            /**
             * Constructs a new BinanceTransaction.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceTransaction);

            /** BinanceTransaction msgs. */
            public msgs: Uint8Array[];

            /** BinanceTransaction signatures. */
            public signatures: Uint8Array[];

            /** BinanceTransaction memo. */
            public memo: string;

            /** BinanceTransaction source. */
            public source: Long;

            /** BinanceTransaction data. */
            public data: Uint8Array;

            /**
             * Creates a new BinanceTransaction instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceTransaction instance
             */
            public static create(properties?: TW.proto.IBinanceTransaction): TW.proto.BinanceTransaction;

            /**
             * Encodes the specified BinanceTransaction message. Does not implicitly {@link TW.proto.BinanceTransaction.verify|verify} messages.
             * @param message BinanceTransaction message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceTransaction, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceTransaction message, length delimited. Does not implicitly {@link TW.proto.BinanceTransaction.verify|verify} messages.
             * @param message BinanceTransaction message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceTransaction, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceTransaction message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceTransaction
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceTransaction;

            /**
             * Decodes a BinanceTransaction message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceTransaction
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceTransaction;

            /**
             * Verifies a BinanceTransaction message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceTransaction message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceTransaction
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceTransaction;

            /**
             * Creates a plain object from a BinanceTransaction message. Also converts values to other types if specified.
             * @param message BinanceTransaction
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceTransaction, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceTransaction to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BinanceSignature. */
        interface IBinanceSignature {

            /** BinanceSignature pubKey */
            pubKey?: (Uint8Array|null);

            /** BinanceSignature signature */
            signature?: (Uint8Array|null);

            /** BinanceSignature accountNumber */
            accountNumber?: (Long|null);

            /** BinanceSignature sequence */
            sequence?: (Long|null);
        }

        /** Represents a BinanceSignature. */
        class BinanceSignature implements IBinanceSignature {

            /**
             * Constructs a new BinanceSignature.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceSignature);

            /** BinanceSignature pubKey. */
            public pubKey: Uint8Array;

            /** BinanceSignature signature. */
            public signature: Uint8Array;

            /** BinanceSignature accountNumber. */
            public accountNumber: Long;

            /** BinanceSignature sequence. */
            public sequence: Long;

            /**
             * Creates a new BinanceSignature instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceSignature instance
             */
            public static create(properties?: TW.proto.IBinanceSignature): TW.proto.BinanceSignature;

            /**
             * Encodes the specified BinanceSignature message. Does not implicitly {@link TW.proto.BinanceSignature.verify|verify} messages.
             * @param message BinanceSignature message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceSignature, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceSignature message, length delimited. Does not implicitly {@link TW.proto.BinanceSignature.verify|verify} messages.
             * @param message BinanceSignature message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceSignature, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceSignature message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceSignature
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSignature;

            /**
             * Decodes a BinanceSignature message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceSignature
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSignature;

            /**
             * Verifies a BinanceSignature message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceSignature message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceSignature
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSignature;

            /**
             * Creates a plain object from a BinanceSignature message. Also converts values to other types if specified.
             * @param message BinanceSignature
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceSignature, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceSignature to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        namespace BinanceSignature {

            /** Properties of a PubKey. */
            interface IPubKey {
            }

            /** Represents a PubKey. */
            class PubKey implements IPubKey {

                /**
                 * Constructs a new PubKey.
                 * @param [properties] Properties to set
                 */
                constructor(properties?: TW.proto.BinanceSignature.IPubKey);

                /**
                 * Creates a new PubKey instance using the specified properties.
                 * @param [properties] Properties to set
                 * @returns PubKey instance
                 */
                public static create(properties?: TW.proto.BinanceSignature.IPubKey): TW.proto.BinanceSignature.PubKey;

                /**
                 * Encodes the specified PubKey message. Does not implicitly {@link TW.proto.BinanceSignature.PubKey.verify|verify} messages.
                 * @param message PubKey message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encode(message: TW.proto.BinanceSignature.IPubKey, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Encodes the specified PubKey message, length delimited. Does not implicitly {@link TW.proto.BinanceSignature.PubKey.verify|verify} messages.
                 * @param message PubKey message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encodeDelimited(message: TW.proto.BinanceSignature.IPubKey, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Decodes a PubKey message from the specified reader or buffer.
                 * @param reader Reader or buffer to decode from
                 * @param [length] Message length if known beforehand
                 * @returns PubKey
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSignature.PubKey;

                /**
                 * Decodes a PubKey message from the specified reader or buffer, length delimited.
                 * @param reader Reader or buffer to decode from
                 * @returns PubKey
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSignature.PubKey;

                /**
                 * Verifies a PubKey message.
                 * @param message Plain object to verify
                 * @returns `null` if valid, otherwise the reason why it is not
                 */
                public static verify(message: { [k: string]: any }): (string|null);

                /**
                 * Creates a PubKey message from a plain object. Also converts values to their respective internal types.
                 * @param object Plain object
                 * @returns PubKey
                 */
                public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSignature.PubKey;

                /**
                 * Creates a plain object from a PubKey message. Also converts values to other types if specified.
                 * @param message PubKey
                 * @param [options] Conversion options
                 * @returns Plain object
                 */
                public static toObject(message: TW.proto.BinanceSignature.PubKey, options?: $protobuf.IConversionOptions): { [k: string]: any };

                /**
                 * Converts this PubKey to JSON.
                 * @returns JSON object
                 */
                public toJSON(): { [k: string]: any };
            }
        }

        /** Properties of a BinanceTradeOrder. */
        interface IBinanceTradeOrder {

            /** BinanceTradeOrder sender */
            sender?: (Uint8Array|null);

            /** BinanceTradeOrder id */
            id?: (string|null);

            /** BinanceTradeOrder symbol */
            symbol?: (string|null);

            /** BinanceTradeOrder ordertype */
            ordertype?: (Long|null);

            /** BinanceTradeOrder side */
            side?: (Long|null);

            /** BinanceTradeOrder price */
            price?: (Long|null);

            /** BinanceTradeOrder quantity */
            quantity?: (Long|null);

            /** BinanceTradeOrder timeinforce */
            timeinforce?: (Long|null);
        }

        /** Represents a BinanceTradeOrder. */
        class BinanceTradeOrder implements IBinanceTradeOrder {

            /**
             * Constructs a new BinanceTradeOrder.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceTradeOrder);

            /** BinanceTradeOrder sender. */
            public sender: Uint8Array;

            /** BinanceTradeOrder id. */
            public id: string;

            /** BinanceTradeOrder symbol. */
            public symbol: string;

            /** BinanceTradeOrder ordertype. */
            public ordertype: Long;

            /** BinanceTradeOrder side. */
            public side: Long;

            /** BinanceTradeOrder price. */
            public price: Long;

            /** BinanceTradeOrder quantity. */
            public quantity: Long;

            /** BinanceTradeOrder timeinforce. */
            public timeinforce: Long;

            /**
             * Creates a new BinanceTradeOrder instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceTradeOrder instance
             */
            public static create(properties?: TW.proto.IBinanceTradeOrder): TW.proto.BinanceTradeOrder;

            /**
             * Encodes the specified BinanceTradeOrder message. Does not implicitly {@link TW.proto.BinanceTradeOrder.verify|verify} messages.
             * @param message BinanceTradeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceTradeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceTradeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceTradeOrder.verify|verify} messages.
             * @param message BinanceTradeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceTradeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceTradeOrder message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceTradeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceTradeOrder;

            /**
             * Decodes a BinanceTradeOrder message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceTradeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceTradeOrder;

            /**
             * Verifies a BinanceTradeOrder message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceTradeOrder message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceTradeOrder
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceTradeOrder;

            /**
             * Creates a plain object from a BinanceTradeOrder message. Also converts values to other types if specified.
             * @param message BinanceTradeOrder
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceTradeOrder, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceTradeOrder to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BinanceCancelTradeOrder. */
        interface IBinanceCancelTradeOrder {

            /** BinanceCancelTradeOrder sender */
            sender?: (Uint8Array|null);

            /** BinanceCancelTradeOrder symbol */
            symbol?: (string|null);

            /** BinanceCancelTradeOrder refid */
            refid?: (string|null);
        }

        /** Represents a BinanceCancelTradeOrder. */
        class BinanceCancelTradeOrder implements IBinanceCancelTradeOrder {

            /**
             * Constructs a new BinanceCancelTradeOrder.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceCancelTradeOrder);

            /** BinanceCancelTradeOrder sender. */
            public sender: Uint8Array;

            /** BinanceCancelTradeOrder symbol. */
            public symbol: string;

            /** BinanceCancelTradeOrder refid. */
            public refid: string;

            /**
             * Creates a new BinanceCancelTradeOrder instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceCancelTradeOrder instance
             */
            public static create(properties?: TW.proto.IBinanceCancelTradeOrder): TW.proto.BinanceCancelTradeOrder;

            /**
             * Encodes the specified BinanceCancelTradeOrder message. Does not implicitly {@link TW.proto.BinanceCancelTradeOrder.verify|verify} messages.
             * @param message BinanceCancelTradeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceCancelTradeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceCancelTradeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceCancelTradeOrder.verify|verify} messages.
             * @param message BinanceCancelTradeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceCancelTradeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceCancelTradeOrder message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceCancelTradeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceCancelTradeOrder;

            /**
             * Decodes a BinanceCancelTradeOrder message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceCancelTradeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceCancelTradeOrder;

            /**
             * Verifies a BinanceCancelTradeOrder message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceCancelTradeOrder message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceCancelTradeOrder
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceCancelTradeOrder;

            /**
             * Creates a plain object from a BinanceCancelTradeOrder message. Also converts values to other types if specified.
             * @param message BinanceCancelTradeOrder
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceCancelTradeOrder, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceCancelTradeOrder to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BinanceSendOrder. */
        interface IBinanceSendOrder {

            /** BinanceSendOrder inputs */
            inputs?: (TW.proto.BinanceSendOrder.IInput[]|null);

            /** BinanceSendOrder outputs */
            outputs?: (TW.proto.BinanceSendOrder.IOutput[]|null);
        }

        /** Represents a BinanceSendOrder. */
        class BinanceSendOrder implements IBinanceSendOrder {

            /**
             * Constructs a new BinanceSendOrder.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceSendOrder);

            /** BinanceSendOrder inputs. */
            public inputs: TW.proto.BinanceSendOrder.IInput[];

            /** BinanceSendOrder outputs. */
            public outputs: TW.proto.BinanceSendOrder.IOutput[];

            /**
             * Creates a new BinanceSendOrder instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceSendOrder instance
             */
            public static create(properties?: TW.proto.IBinanceSendOrder): TW.proto.BinanceSendOrder;

            /**
             * Encodes the specified BinanceSendOrder message. Does not implicitly {@link TW.proto.BinanceSendOrder.verify|verify} messages.
             * @param message BinanceSendOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceSendOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceSendOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.verify|verify} messages.
             * @param message BinanceSendOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceSendOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceSendOrder message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceSendOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSendOrder;

            /**
             * Decodes a BinanceSendOrder message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceSendOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSendOrder;

            /**
             * Verifies a BinanceSendOrder message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceSendOrder message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceSendOrder
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSendOrder;

            /**
             * Creates a plain object from a BinanceSendOrder message. Also converts values to other types if specified.
             * @param message BinanceSendOrder
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceSendOrder, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceSendOrder to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        namespace BinanceSendOrder {

            /** Properties of a Token. */
            interface IToken {

                /** Token denom */
                denom?: (string|null);

                /** Token amount */
                amount?: (Long|null);
            }

            /** Represents a Token. */
            class Token implements IToken {

                /**
                 * Constructs a new Token.
                 * @param [properties] Properties to set
                 */
                constructor(properties?: TW.proto.BinanceSendOrder.IToken);

                /** Token denom. */
                public denom: string;

                /** Token amount. */
                public amount: Long;

                /**
                 * Creates a new Token instance using the specified properties.
                 * @param [properties] Properties to set
                 * @returns Token instance
                 */
                public static create(properties?: TW.proto.BinanceSendOrder.IToken): TW.proto.BinanceSendOrder.Token;

                /**
                 * Encodes the specified Token message. Does not implicitly {@link TW.proto.BinanceSendOrder.Token.verify|verify} messages.
                 * @param message Token message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encode(message: TW.proto.BinanceSendOrder.IToken, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Encodes the specified Token message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.Token.verify|verify} messages.
                 * @param message Token message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encodeDelimited(message: TW.proto.BinanceSendOrder.IToken, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Decodes a Token message from the specified reader or buffer.
                 * @param reader Reader or buffer to decode from
                 * @param [length] Message length if known beforehand
                 * @returns Token
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSendOrder.Token;

                /**
                 * Decodes a Token message from the specified reader or buffer, length delimited.
                 * @param reader Reader or buffer to decode from
                 * @returns Token
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSendOrder.Token;

                /**
                 * Verifies a Token message.
                 * @param message Plain object to verify
                 * @returns `null` if valid, otherwise the reason why it is not
                 */
                public static verify(message: { [k: string]: any }): (string|null);

                /**
                 * Creates a Token message from a plain object. Also converts values to their respective internal types.
                 * @param object Plain object
                 * @returns Token
                 */
                public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSendOrder.Token;

                /**
                 * Creates a plain object from a Token message. Also converts values to other types if specified.
                 * @param message Token
                 * @param [options] Conversion options
                 * @returns Plain object
                 */
                public static toObject(message: TW.proto.BinanceSendOrder.Token, options?: $protobuf.IConversionOptions): { [k: string]: any };

                /**
                 * Converts this Token to JSON.
                 * @returns JSON object
                 */
                public toJSON(): { [k: string]: any };
            }

            /** Properties of an Input. */
            interface IInput {

                /** Input address */
                address?: (Uint8Array|null);

                /** Input coins */
                coins?: (TW.proto.BinanceSendOrder.IToken[]|null);
            }

            /** Represents an Input. */
            class Input implements IInput {

                /**
                 * Constructs a new Input.
                 * @param [properties] Properties to set
                 */
                constructor(properties?: TW.proto.BinanceSendOrder.IInput);

                /** Input address. */
                public address: Uint8Array;

                /** Input coins. */
                public coins: TW.proto.BinanceSendOrder.IToken[];

                /**
                 * Creates a new Input instance using the specified properties.
                 * @param [properties] Properties to set
                 * @returns Input instance
                 */
                public static create(properties?: TW.proto.BinanceSendOrder.IInput): TW.proto.BinanceSendOrder.Input;

                /**
                 * Encodes the specified Input message. Does not implicitly {@link TW.proto.BinanceSendOrder.Input.verify|verify} messages.
                 * @param message Input message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encode(message: TW.proto.BinanceSendOrder.IInput, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Encodes the specified Input message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.Input.verify|verify} messages.
                 * @param message Input message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encodeDelimited(message: TW.proto.BinanceSendOrder.IInput, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Decodes an Input message from the specified reader or buffer.
                 * @param reader Reader or buffer to decode from
                 * @param [length] Message length if known beforehand
                 * @returns Input
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSendOrder.Input;

                /**
                 * Decodes an Input message from the specified reader or buffer, length delimited.
                 * @param reader Reader or buffer to decode from
                 * @returns Input
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSendOrder.Input;

                /**
                 * Verifies an Input message.
                 * @param message Plain object to verify
                 * @returns `null` if valid, otherwise the reason why it is not
                 */
                public static verify(message: { [k: string]: any }): (string|null);

                /**
                 * Creates an Input message from a plain object. Also converts values to their respective internal types.
                 * @param object Plain object
                 * @returns Input
                 */
                public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSendOrder.Input;

                /**
                 * Creates a plain object from an Input message. Also converts values to other types if specified.
                 * @param message Input
                 * @param [options] Conversion options
                 * @returns Plain object
                 */
                public static toObject(message: TW.proto.BinanceSendOrder.Input, options?: $protobuf.IConversionOptions): { [k: string]: any };

                /**
                 * Converts this Input to JSON.
                 * @returns JSON object
                 */
                public toJSON(): { [k: string]: any };
            }

            /** Properties of an Output. */
            interface IOutput {

                /** Output address */
                address?: (Uint8Array|null);

                /** Output coins */
                coins?: (TW.proto.BinanceSendOrder.IToken[]|null);
            }

            /** Represents an Output. */
            class Output implements IOutput {

                /**
                 * Constructs a new Output.
                 * @param [properties] Properties to set
                 */
                constructor(properties?: TW.proto.BinanceSendOrder.IOutput);

                /** Output address. */
                public address: Uint8Array;

                /** Output coins. */
                public coins: TW.proto.BinanceSendOrder.IToken[];

                /**
                 * Creates a new Output instance using the specified properties.
                 * @param [properties] Properties to set
                 * @returns Output instance
                 */
                public static create(properties?: TW.proto.BinanceSendOrder.IOutput): TW.proto.BinanceSendOrder.Output;

                /**
                 * Encodes the specified Output message. Does not implicitly {@link TW.proto.BinanceSendOrder.Output.verify|verify} messages.
                 * @param message Output message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encode(message: TW.proto.BinanceSendOrder.IOutput, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Encodes the specified Output message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.Output.verify|verify} messages.
                 * @param message Output message or plain object to encode
                 * @param [writer] Writer to encode to
                 * @returns Writer
                 */
                public static encodeDelimited(message: TW.proto.BinanceSendOrder.IOutput, writer?: $protobuf.Writer): $protobuf.Writer;

                /**
                 * Decodes an Output message from the specified reader or buffer.
                 * @param reader Reader or buffer to decode from
                 * @param [length] Message length if known beforehand
                 * @returns Output
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSendOrder.Output;

                /**
                 * Decodes an Output message from the specified reader or buffer, length delimited.
                 * @param reader Reader or buffer to decode from
                 * @returns Output
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSendOrder.Output;

                /**
                 * Verifies an Output message.
                 * @param message Plain object to verify
                 * @returns `null` if valid, otherwise the reason why it is not
                 */
                public static verify(message: { [k: string]: any }): (string|null);

                /**
                 * Creates an Output message from a plain object. Also converts values to their respective internal types.
                 * @param object Plain object
                 * @returns Output
                 */
                public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSendOrder.Output;

                /**
                 * Creates a plain object from an Output message. Also converts values to other types if specified.
                 * @param message Output
                 * @param [options] Conversion options
                 * @returns Plain object
                 */
                public static toObject(message: TW.proto.BinanceSendOrder.Output, options?: $protobuf.IConversionOptions): { [k: string]: any };

                /**
                 * Converts this Output to JSON.
                 * @returns JSON object
                 */
                public toJSON(): { [k: string]: any };
            }
        }

        /** Properties of a BinanceTokenFreezeOrder. */
        interface IBinanceTokenFreezeOrder {

            /** BinanceTokenFreezeOrder from */
            from?: (Uint8Array|null);

            /** BinanceTokenFreezeOrder symbol */
            symbol?: (string|null);

            /** BinanceTokenFreezeOrder amount */
            amount?: (Long|null);
        }

        /** Represents a BinanceTokenFreezeOrder. */
        class BinanceTokenFreezeOrder implements IBinanceTokenFreezeOrder {

            /**
             * Constructs a new BinanceTokenFreezeOrder.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceTokenFreezeOrder);

            /** BinanceTokenFreezeOrder from. */
            public from: Uint8Array;

            /** BinanceTokenFreezeOrder symbol. */
            public symbol: string;

            /** BinanceTokenFreezeOrder amount. */
            public amount: Long;

            /**
             * Creates a new BinanceTokenFreezeOrder instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceTokenFreezeOrder instance
             */
            public static create(properties?: TW.proto.IBinanceTokenFreezeOrder): TW.proto.BinanceTokenFreezeOrder;

            /**
             * Encodes the specified BinanceTokenFreezeOrder message. Does not implicitly {@link TW.proto.BinanceTokenFreezeOrder.verify|verify} messages.
             * @param message BinanceTokenFreezeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceTokenFreezeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceTokenFreezeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceTokenFreezeOrder.verify|verify} messages.
             * @param message BinanceTokenFreezeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceTokenFreezeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceTokenFreezeOrder message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceTokenFreezeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceTokenFreezeOrder;

            /**
             * Decodes a BinanceTokenFreezeOrder message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceTokenFreezeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceTokenFreezeOrder;

            /**
             * Verifies a BinanceTokenFreezeOrder message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceTokenFreezeOrder message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceTokenFreezeOrder
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceTokenFreezeOrder;

            /**
             * Creates a plain object from a BinanceTokenFreezeOrder message. Also converts values to other types if specified.
             * @param message BinanceTokenFreezeOrder
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceTokenFreezeOrder, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceTokenFreezeOrder to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BinanceTokenUnfreezeOrder. */
        interface IBinanceTokenUnfreezeOrder {

            /** BinanceTokenUnfreezeOrder from */
            from?: (Uint8Array|null);

            /** BinanceTokenUnfreezeOrder symbol */
            symbol?: (string|null);

            /** BinanceTokenUnfreezeOrder amount */
            amount?: (Long|null);
        }

        /** Represents a BinanceTokenUnfreezeOrder. */
        class BinanceTokenUnfreezeOrder implements IBinanceTokenUnfreezeOrder {

            /**
             * Constructs a new BinanceTokenUnfreezeOrder.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceTokenUnfreezeOrder);

            /** BinanceTokenUnfreezeOrder from. */
            public from: Uint8Array;

            /** BinanceTokenUnfreezeOrder symbol. */
            public symbol: string;

            /** BinanceTokenUnfreezeOrder amount. */
            public amount: Long;

            /**
             * Creates a new BinanceTokenUnfreezeOrder instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceTokenUnfreezeOrder instance
             */
            public static create(properties?: TW.proto.IBinanceTokenUnfreezeOrder): TW.proto.BinanceTokenUnfreezeOrder;

            /**
             * Encodes the specified BinanceTokenUnfreezeOrder message. Does not implicitly {@link TW.proto.BinanceTokenUnfreezeOrder.verify|verify} messages.
             * @param message BinanceTokenUnfreezeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceTokenUnfreezeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceTokenUnfreezeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceTokenUnfreezeOrder.verify|verify} messages.
             * @param message BinanceTokenUnfreezeOrder message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceTokenUnfreezeOrder, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceTokenUnfreezeOrder message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceTokenUnfreezeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceTokenUnfreezeOrder;

            /**
             * Decodes a BinanceTokenUnfreezeOrder message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceTokenUnfreezeOrder
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceTokenUnfreezeOrder;

            /**
             * Verifies a BinanceTokenUnfreezeOrder message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceTokenUnfreezeOrder message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceTokenUnfreezeOrder
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceTokenUnfreezeOrder;

            /**
             * Creates a plain object from a BinanceTokenUnfreezeOrder message. Also converts values to other types if specified.
             * @param message BinanceTokenUnfreezeOrder
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceTokenUnfreezeOrder, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceTokenUnfreezeOrder to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }

        /** Properties of a BinanceSigningInput. */
        interface IBinanceSigningInput {

            /** BinanceSigningInput chainId */
            chainId?: (string|null);

            /** BinanceSigningInput accountNumber */
            accountNumber?: (Long|null);

            /** BinanceSigningInput sequence */
            sequence?: (Long|null);

            /** BinanceSigningInput source */
            source?: (Long|null);

            /** BinanceSigningInput memo */
            memo?: (string|null);

            /** BinanceSigningInput privateKey */
            privateKey?: (Uint8Array|null);

            /** BinanceSigningInput tradeOrder */
            tradeOrder?: (TW.proto.IBinanceTradeOrder|null);

            /** BinanceSigningInput cancelTradeOrder */
            cancelTradeOrder?: (TW.proto.IBinanceCancelTradeOrder|null);

            /** BinanceSigningInput sendOrder */
            sendOrder?: (TW.proto.IBinanceSendOrder|null);

            /** BinanceSigningInput freezeOrder */
            freezeOrder?: (TW.proto.IBinanceTokenFreezeOrder|null);

            /** BinanceSigningInput unfreezeOrder */
            unfreezeOrder?: (TW.proto.IBinanceTokenUnfreezeOrder|null);
        }

        /** Represents a BinanceSigningInput. */
        class BinanceSigningInput implements IBinanceSigningInput {

            /**
             * Constructs a new BinanceSigningInput.
             * @param [properties] Properties to set
             */
            constructor(properties?: TW.proto.IBinanceSigningInput);

            /** BinanceSigningInput chainId. */
            public chainId: string;

            /** BinanceSigningInput accountNumber. */
            public accountNumber: Long;

            /** BinanceSigningInput sequence. */
            public sequence: Long;

            /** BinanceSigningInput source. */
            public source: Long;

            /** BinanceSigningInput memo. */
            public memo: string;

            /** BinanceSigningInput privateKey. */
            public privateKey: Uint8Array;

            /** BinanceSigningInput tradeOrder. */
            public tradeOrder?: (TW.proto.IBinanceTradeOrder|null);

            /** BinanceSigningInput cancelTradeOrder. */
            public cancelTradeOrder?: (TW.proto.IBinanceCancelTradeOrder|null);

            /** BinanceSigningInput sendOrder. */
            public sendOrder?: (TW.proto.IBinanceSendOrder|null);

            /** BinanceSigningInput freezeOrder. */
            public freezeOrder?: (TW.proto.IBinanceTokenFreezeOrder|null);

            /** BinanceSigningInput unfreezeOrder. */
            public unfreezeOrder?: (TW.proto.IBinanceTokenUnfreezeOrder|null);

            /** BinanceSigningInput orderOneof. */
            public orderOneof?: ("tradeOrder"|"cancelTradeOrder"|"sendOrder"|"freezeOrder"|"unfreezeOrder");

            /**
             * Creates a new BinanceSigningInput instance using the specified properties.
             * @param [properties] Properties to set
             * @returns BinanceSigningInput instance
             */
            public static create(properties?: TW.proto.IBinanceSigningInput): TW.proto.BinanceSigningInput;

            /**
             * Encodes the specified BinanceSigningInput message. Does not implicitly {@link TW.proto.BinanceSigningInput.verify|verify} messages.
             * @param message BinanceSigningInput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: TW.proto.IBinanceSigningInput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified BinanceSigningInput message, length delimited. Does not implicitly {@link TW.proto.BinanceSigningInput.verify|verify} messages.
             * @param message BinanceSigningInput message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: TW.proto.IBinanceSigningInput, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes a BinanceSigningInput message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns BinanceSigningInput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): TW.proto.BinanceSigningInput;

            /**
             * Decodes a BinanceSigningInput message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns BinanceSigningInput
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): TW.proto.BinanceSigningInput;

            /**
             * Verifies a BinanceSigningInput message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates a BinanceSigningInput message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns BinanceSigningInput
             */
            public static fromObject(object: { [k: string]: any }): TW.proto.BinanceSigningInput;

            /**
             * Creates a plain object from a BinanceSigningInput message. Also converts values to other types if specified.
             * @param message BinanceSigningInput
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: TW.proto.BinanceSigningInput, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this BinanceSigningInput to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }
    }
}

/** Namespace google. */
export namespace google {

    /** Namespace protobuf. */
    namespace protobuf {

        /** Properties of an Any. */
        interface IAny {

            /** Any type_url */
            type_url?: (string|null);

            /** Any value */
            value?: (Uint8Array|null);
        }

        /** Represents an Any. */
        class Any implements IAny {

            /**
             * Constructs a new Any.
             * @param [properties] Properties to set
             */
            constructor(properties?: google.protobuf.IAny);

            /** Any type_url. */
            public type_url: string;

            /** Any value. */
            public value: Uint8Array;

            /**
             * Creates a new Any instance using the specified properties.
             * @param [properties] Properties to set
             * @returns Any instance
             */
            public static create(properties?: google.protobuf.IAny): google.protobuf.Any;

            /**
             * Encodes the specified Any message. Does not implicitly {@link google.protobuf.Any.verify|verify} messages.
             * @param message Any message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encode(message: google.protobuf.IAny, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Encodes the specified Any message, length delimited. Does not implicitly {@link google.protobuf.Any.verify|verify} messages.
             * @param message Any message or plain object to encode
             * @param [writer] Writer to encode to
             * @returns Writer
             */
            public static encodeDelimited(message: google.protobuf.IAny, writer?: $protobuf.Writer): $protobuf.Writer;

            /**
             * Decodes an Any message from the specified reader or buffer.
             * @param reader Reader or buffer to decode from
             * @param [length] Message length if known beforehand
             * @returns Any
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decode(reader: ($protobuf.Reader|Uint8Array), length?: number): google.protobuf.Any;

            /**
             * Decodes an Any message from the specified reader or buffer, length delimited.
             * @param reader Reader or buffer to decode from
             * @returns Any
             * @throws {Error} If the payload is not a reader or valid buffer
             * @throws {$protobuf.util.ProtocolError} If required fields are missing
             */
            public static decodeDelimited(reader: ($protobuf.Reader|Uint8Array)): google.protobuf.Any;

            /**
             * Verifies an Any message.
             * @param message Plain object to verify
             * @returns `null` if valid, otherwise the reason why it is not
             */
            public static verify(message: { [k: string]: any }): (string|null);

            /**
             * Creates an Any message from a plain object. Also converts values to their respective internal types.
             * @param object Plain object
             * @returns Any
             */
            public static fromObject(object: { [k: string]: any }): google.protobuf.Any;

            /**
             * Creates a plain object from an Any message. Also converts values to other types if specified.
             * @param message Any
             * @param [options] Conversion options
             * @returns Plain object
             */
            public static toObject(message: google.protobuf.Any, options?: $protobuf.IConversionOptions): { [k: string]: any };

            /**
             * Converts this Any to JSON.
             * @returns JSON object
             */
            public toJSON(): { [k: string]: any };
        }
    }
}
