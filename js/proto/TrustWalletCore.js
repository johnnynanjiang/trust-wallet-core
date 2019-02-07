/*eslint-disable block-scoped-var, id-length, no-control-regex, no-magic-numbers, no-prototype-builtins, no-redeclare, no-shadow, no-var, sort-vars*/
(function(global, factory) { /* global define, require, module */

    /* AMD */ if (typeof define === 'function' && define.amd)
        define(["protobufjs/minimal"], factory);

    /* CommonJS */ else if (typeof require === 'function' && typeof module === 'object' && module && module.exports)
        module.exports = factory(require("protobufjs/minimal"));

})(this, function($protobuf) {
    "use strict";

    // Common aliases
    var $Reader = $protobuf.Reader, $Writer = $protobuf.Writer, $util = $protobuf.util;
    
    // Exported root namespace
    var $root = $protobuf.roots["default"] || ($protobuf.roots["default"] = {});
    
    $root.TW = (function() {
    
        /**
         * Namespace TW.
         * @exports TW
         * @namespace
         */
        var TW = {};
    
        TW.proto = (function() {
    
            /**
             * Namespace proto.
             * @memberof TW
             * @namespace
             */
            var proto = {};
    
            proto.Result = (function() {
    
                /**
                 * Properties of a Result.
                 * @memberof TW.proto
                 * @interface IResult
                 * @property {boolean|null} [success] Result success
                 * @property {string|null} [error] Result error
                 * @property {Array.<google.protobuf.IAny>|null} [objects] Result objects
                 */
    
                /**
                 * Constructs a new Result.
                 * @memberof TW.proto
                 * @classdesc Represents a Result.
                 * @implements IResult
                 * @constructor
                 * @param {TW.proto.IResult=} [properties] Properties to set
                 */
                function Result(properties) {
                    this.objects = [];
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * Result success.
                 * @member {boolean} success
                 * @memberof TW.proto.Result
                 * @instance
                 */
                Result.prototype.success = false;
    
                /**
                 * Result error.
                 * @member {string} error
                 * @memberof TW.proto.Result
                 * @instance
                 */
                Result.prototype.error = "";
    
                /**
                 * Result objects.
                 * @member {Array.<google.protobuf.IAny>} objects
                 * @memberof TW.proto.Result
                 * @instance
                 */
                Result.prototype.objects = $util.emptyArray;
    
                /**
                 * Creates a new Result instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.Result
                 * @static
                 * @param {TW.proto.IResult=} [properties] Properties to set
                 * @returns {TW.proto.Result} Result instance
                 */
                Result.create = function create(properties) {
                    return new Result(properties);
                };
    
                /**
                 * Encodes the specified Result message. Does not implicitly {@link TW.proto.Result.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.Result
                 * @static
                 * @param {TW.proto.IResult} message Result message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                Result.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.success != null && message.hasOwnProperty("success"))
                        writer.uint32(/* id 1, wireType 0 =*/8).bool(message.success);
                    if (message.error != null && message.hasOwnProperty("error"))
                        writer.uint32(/* id 2, wireType 2 =*/18).string(message.error);
                    if (message.objects != null && message.objects.length)
                        for (var i = 0; i < message.objects.length; ++i)
                            $root.google.protobuf.Any.encode(message.objects[i], writer.uint32(/* id 3, wireType 2 =*/26).fork()).ldelim();
                    return writer;
                };
    
                /**
                 * Encodes the specified Result message, length delimited. Does not implicitly {@link TW.proto.Result.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.Result
                 * @static
                 * @param {TW.proto.IResult} message Result message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                Result.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a Result message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.Result
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.Result} Result
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                Result.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.Result();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.success = reader.bool();
                            break;
                        case 2:
                            message.error = reader.string();
                            break;
                        case 3:
                            if (!(message.objects && message.objects.length))
                                message.objects = [];
                            message.objects.push($root.google.protobuf.Any.decode(reader, reader.uint32()));
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a Result message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.Result
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.Result} Result
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                Result.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a Result message.
                 * @function verify
                 * @memberof TW.proto.Result
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                Result.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.success != null && message.hasOwnProperty("success"))
                        if (typeof message.success !== "boolean")
                            return "success: boolean expected";
                    if (message.error != null && message.hasOwnProperty("error"))
                        if (!$util.isString(message.error))
                            return "error: string expected";
                    if (message.objects != null && message.hasOwnProperty("objects")) {
                        if (!Array.isArray(message.objects))
                            return "objects: array expected";
                        for (var i = 0; i < message.objects.length; ++i) {
                            var error = $root.google.protobuf.Any.verify(message.objects[i]);
                            if (error)
                                return "objects." + error;
                        }
                    }
                    return null;
                };
    
                /**
                 * Creates a Result message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.Result
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.Result} Result
                 */
                Result.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.Result)
                        return object;
                    var message = new $root.TW.proto.Result();
                    if (object.success != null)
                        message.success = Boolean(object.success);
                    if (object.error != null)
                        message.error = String(object.error);
                    if (object.objects) {
                        if (!Array.isArray(object.objects))
                            throw TypeError(".TW.proto.Result.objects: array expected");
                        message.objects = [];
                        for (var i = 0; i < object.objects.length; ++i) {
                            if (typeof object.objects[i] !== "object")
                                throw TypeError(".TW.proto.Result.objects: object expected");
                            message.objects[i] = $root.google.protobuf.Any.fromObject(object.objects[i]);
                        }
                    }
                    return message;
                };
    
                /**
                 * Creates a plain object from a Result message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.Result
                 * @static
                 * @param {TW.proto.Result} message Result
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                Result.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.arrays || options.defaults)
                        object.objects = [];
                    if (options.defaults) {
                        object.success = false;
                        object.error = "";
                    }
                    if (message.success != null && message.hasOwnProperty("success"))
                        object.success = message.success;
                    if (message.error != null && message.hasOwnProperty("error"))
                        object.error = message.error;
                    if (message.objects && message.objects.length) {
                        object.objects = [];
                        for (var j = 0; j < message.objects.length; ++j)
                            object.objects[j] = $root.google.protobuf.Any.toObject(message.objects[j], options);
                    }
                    return object;
                };
    
                /**
                 * Converts this Result to JSON.
                 * @function toJSON
                 * @memberof TW.proto.Result
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                Result.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return Result;
            })();
    
            proto.BitcoinTransaction = (function() {
    
                /**
                 * Properties of a BitcoinTransaction.
                 * @memberof TW.proto
                 * @interface IBitcoinTransaction
                 * @property {number|null} [version] BitcoinTransaction version
                 * @property {number|null} [lockTime] BitcoinTransaction lockTime
                 * @property {Array.<TW.proto.IBitcoinTransactionInput>|null} [inputs] BitcoinTransaction inputs
                 * @property {Array.<TW.proto.IBitcoinTransactionOutput>|null} [outputs] BitcoinTransaction outputs
                 */
    
                /**
                 * Constructs a new BitcoinTransaction.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinTransaction.
                 * @implements IBitcoinTransaction
                 * @constructor
                 * @param {TW.proto.IBitcoinTransaction=} [properties] Properties to set
                 */
                function BitcoinTransaction(properties) {
                    this.inputs = [];
                    this.outputs = [];
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinTransaction version.
                 * @member {number} version
                 * @memberof TW.proto.BitcoinTransaction
                 * @instance
                 */
                BitcoinTransaction.prototype.version = 0;
    
                /**
                 * BitcoinTransaction lockTime.
                 * @member {number} lockTime
                 * @memberof TW.proto.BitcoinTransaction
                 * @instance
                 */
                BitcoinTransaction.prototype.lockTime = 0;
    
                /**
                 * BitcoinTransaction inputs.
                 * @member {Array.<TW.proto.IBitcoinTransactionInput>} inputs
                 * @memberof TW.proto.BitcoinTransaction
                 * @instance
                 */
                BitcoinTransaction.prototype.inputs = $util.emptyArray;
    
                /**
                 * BitcoinTransaction outputs.
                 * @member {Array.<TW.proto.IBitcoinTransactionOutput>} outputs
                 * @memberof TW.proto.BitcoinTransaction
                 * @instance
                 */
                BitcoinTransaction.prototype.outputs = $util.emptyArray;
    
                /**
                 * Creates a new BitcoinTransaction instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {TW.proto.IBitcoinTransaction=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinTransaction} BitcoinTransaction instance
                 */
                BitcoinTransaction.create = function create(properties) {
                    return new BitcoinTransaction(properties);
                };
    
                /**
                 * Encodes the specified BitcoinTransaction message. Does not implicitly {@link TW.proto.BitcoinTransaction.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {TW.proto.IBitcoinTransaction} message BitcoinTransaction message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinTransaction.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.version != null && message.hasOwnProperty("version"))
                        writer.uint32(/* id 1, wireType 0 =*/8).sint32(message.version);
                    if (message.lockTime != null && message.hasOwnProperty("lockTime"))
                        writer.uint32(/* id 2, wireType 0 =*/16).uint32(message.lockTime);
                    if (message.inputs != null && message.inputs.length)
                        for (var i = 0; i < message.inputs.length; ++i)
                            $root.TW.proto.BitcoinTransactionInput.encode(message.inputs[i], writer.uint32(/* id 3, wireType 2 =*/26).fork()).ldelim();
                    if (message.outputs != null && message.outputs.length)
                        for (var i = 0; i < message.outputs.length; ++i)
                            $root.TW.proto.BitcoinTransactionOutput.encode(message.outputs[i], writer.uint32(/* id 4, wireType 2 =*/34).fork()).ldelim();
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinTransaction message, length delimited. Does not implicitly {@link TW.proto.BitcoinTransaction.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {TW.proto.IBitcoinTransaction} message BitcoinTransaction message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinTransaction.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinTransaction message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinTransaction} BitcoinTransaction
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinTransaction.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinTransaction();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.version = reader.sint32();
                            break;
                        case 2:
                            message.lockTime = reader.uint32();
                            break;
                        case 3:
                            if (!(message.inputs && message.inputs.length))
                                message.inputs = [];
                            message.inputs.push($root.TW.proto.BitcoinTransactionInput.decode(reader, reader.uint32()));
                            break;
                        case 4:
                            if (!(message.outputs && message.outputs.length))
                                message.outputs = [];
                            message.outputs.push($root.TW.proto.BitcoinTransactionOutput.decode(reader, reader.uint32()));
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinTransaction message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinTransaction} BitcoinTransaction
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinTransaction.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinTransaction message.
                 * @function verify
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinTransaction.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.version != null && message.hasOwnProperty("version"))
                        if (!$util.isInteger(message.version))
                            return "version: integer expected";
                    if (message.lockTime != null && message.hasOwnProperty("lockTime"))
                        if (!$util.isInteger(message.lockTime))
                            return "lockTime: integer expected";
                    if (message.inputs != null && message.hasOwnProperty("inputs")) {
                        if (!Array.isArray(message.inputs))
                            return "inputs: array expected";
                        for (var i = 0; i < message.inputs.length; ++i) {
                            var error = $root.TW.proto.BitcoinTransactionInput.verify(message.inputs[i]);
                            if (error)
                                return "inputs." + error;
                        }
                    }
                    if (message.outputs != null && message.hasOwnProperty("outputs")) {
                        if (!Array.isArray(message.outputs))
                            return "outputs: array expected";
                        for (var i = 0; i < message.outputs.length; ++i) {
                            var error = $root.TW.proto.BitcoinTransactionOutput.verify(message.outputs[i]);
                            if (error)
                                return "outputs." + error;
                        }
                    }
                    return null;
                };
    
                /**
                 * Creates a BitcoinTransaction message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinTransaction} BitcoinTransaction
                 */
                BitcoinTransaction.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinTransaction)
                        return object;
                    var message = new $root.TW.proto.BitcoinTransaction();
                    if (object.version != null)
                        message.version = object.version | 0;
                    if (object.lockTime != null)
                        message.lockTime = object.lockTime >>> 0;
                    if (object.inputs) {
                        if (!Array.isArray(object.inputs))
                            throw TypeError(".TW.proto.BitcoinTransaction.inputs: array expected");
                        message.inputs = [];
                        for (var i = 0; i < object.inputs.length; ++i) {
                            if (typeof object.inputs[i] !== "object")
                                throw TypeError(".TW.proto.BitcoinTransaction.inputs: object expected");
                            message.inputs[i] = $root.TW.proto.BitcoinTransactionInput.fromObject(object.inputs[i]);
                        }
                    }
                    if (object.outputs) {
                        if (!Array.isArray(object.outputs))
                            throw TypeError(".TW.proto.BitcoinTransaction.outputs: array expected");
                        message.outputs = [];
                        for (var i = 0; i < object.outputs.length; ++i) {
                            if (typeof object.outputs[i] !== "object")
                                throw TypeError(".TW.proto.BitcoinTransaction.outputs: object expected");
                            message.outputs[i] = $root.TW.proto.BitcoinTransactionOutput.fromObject(object.outputs[i]);
                        }
                    }
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinTransaction message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinTransaction
                 * @static
                 * @param {TW.proto.BitcoinTransaction} message BitcoinTransaction
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinTransaction.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.arrays || options.defaults) {
                        object.inputs = [];
                        object.outputs = [];
                    }
                    if (options.defaults) {
                        object.version = 0;
                        object.lockTime = 0;
                    }
                    if (message.version != null && message.hasOwnProperty("version"))
                        object.version = message.version;
                    if (message.lockTime != null && message.hasOwnProperty("lockTime"))
                        object.lockTime = message.lockTime;
                    if (message.inputs && message.inputs.length) {
                        object.inputs = [];
                        for (var j = 0; j < message.inputs.length; ++j)
                            object.inputs[j] = $root.TW.proto.BitcoinTransactionInput.toObject(message.inputs[j], options);
                    }
                    if (message.outputs && message.outputs.length) {
                        object.outputs = [];
                        for (var j = 0; j < message.outputs.length; ++j)
                            object.outputs[j] = $root.TW.proto.BitcoinTransactionOutput.toObject(message.outputs[j], options);
                    }
                    return object;
                };
    
                /**
                 * Converts this BitcoinTransaction to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinTransaction
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinTransaction.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinTransaction;
            })();
    
            proto.BitcoinTransactionInput = (function() {
    
                /**
                 * Properties of a BitcoinTransactionInput.
                 * @memberof TW.proto
                 * @interface IBitcoinTransactionInput
                 * @property {TW.proto.IBitcoinOutPoint|null} [previousOutput] BitcoinTransactionInput previousOutput
                 * @property {number|null} [sequence] BitcoinTransactionInput sequence
                 * @property {Uint8Array|null} [script] BitcoinTransactionInput script
                 */
    
                /**
                 * Constructs a new BitcoinTransactionInput.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinTransactionInput.
                 * @implements IBitcoinTransactionInput
                 * @constructor
                 * @param {TW.proto.IBitcoinTransactionInput=} [properties] Properties to set
                 */
                function BitcoinTransactionInput(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinTransactionInput previousOutput.
                 * @member {TW.proto.IBitcoinOutPoint|null|undefined} previousOutput
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @instance
                 */
                BitcoinTransactionInput.prototype.previousOutput = null;
    
                /**
                 * BitcoinTransactionInput sequence.
                 * @member {number} sequence
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @instance
                 */
                BitcoinTransactionInput.prototype.sequence = 0;
    
                /**
                 * BitcoinTransactionInput script.
                 * @member {Uint8Array} script
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @instance
                 */
                BitcoinTransactionInput.prototype.script = $util.newBuffer([]);
    
                /**
                 * Creates a new BitcoinTransactionInput instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {TW.proto.IBitcoinTransactionInput=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinTransactionInput} BitcoinTransactionInput instance
                 */
                BitcoinTransactionInput.create = function create(properties) {
                    return new BitcoinTransactionInput(properties);
                };
    
                /**
                 * Encodes the specified BitcoinTransactionInput message. Does not implicitly {@link TW.proto.BitcoinTransactionInput.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {TW.proto.IBitcoinTransactionInput} message BitcoinTransactionInput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinTransactionInput.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.previousOutput != null && message.hasOwnProperty("previousOutput"))
                        $root.TW.proto.BitcoinOutPoint.encode(message.previousOutput, writer.uint32(/* id 1, wireType 2 =*/10).fork()).ldelim();
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        writer.uint32(/* id 2, wireType 0 =*/16).uint32(message.sequence);
                    if (message.script != null && message.hasOwnProperty("script"))
                        writer.uint32(/* id 3, wireType 2 =*/26).bytes(message.script);
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinTransactionInput message, length delimited. Does not implicitly {@link TW.proto.BitcoinTransactionInput.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {TW.proto.IBitcoinTransactionInput} message BitcoinTransactionInput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinTransactionInput.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinTransactionInput message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinTransactionInput} BitcoinTransactionInput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinTransactionInput.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinTransactionInput();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.previousOutput = $root.TW.proto.BitcoinOutPoint.decode(reader, reader.uint32());
                            break;
                        case 2:
                            message.sequence = reader.uint32();
                            break;
                        case 3:
                            message.script = reader.bytes();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinTransactionInput message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinTransactionInput} BitcoinTransactionInput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinTransactionInput.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinTransactionInput message.
                 * @function verify
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinTransactionInput.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.previousOutput != null && message.hasOwnProperty("previousOutput")) {
                        var error = $root.TW.proto.BitcoinOutPoint.verify(message.previousOutput);
                        if (error)
                            return "previousOutput." + error;
                    }
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        if (!$util.isInteger(message.sequence))
                            return "sequence: integer expected";
                    if (message.script != null && message.hasOwnProperty("script"))
                        if (!(message.script && typeof message.script.length === "number" || $util.isString(message.script)))
                            return "script: buffer expected";
                    return null;
                };
    
                /**
                 * Creates a BitcoinTransactionInput message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinTransactionInput} BitcoinTransactionInput
                 */
                BitcoinTransactionInput.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinTransactionInput)
                        return object;
                    var message = new $root.TW.proto.BitcoinTransactionInput();
                    if (object.previousOutput != null) {
                        if (typeof object.previousOutput !== "object")
                            throw TypeError(".TW.proto.BitcoinTransactionInput.previousOutput: object expected");
                        message.previousOutput = $root.TW.proto.BitcoinOutPoint.fromObject(object.previousOutput);
                    }
                    if (object.sequence != null)
                        message.sequence = object.sequence >>> 0;
                    if (object.script != null)
                        if (typeof object.script === "string")
                            $util.base64.decode(object.script, message.script = $util.newBuffer($util.base64.length(object.script)), 0);
                        else if (object.script.length)
                            message.script = object.script;
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinTransactionInput message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @static
                 * @param {TW.proto.BitcoinTransactionInput} message BitcoinTransactionInput
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinTransactionInput.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        object.previousOutput = null;
                        object.sequence = 0;
                        if (options.bytes === String)
                            object.script = "";
                        else {
                            object.script = [];
                            if (options.bytes !== Array)
                                object.script = $util.newBuffer(object.script);
                        }
                    }
                    if (message.previousOutput != null && message.hasOwnProperty("previousOutput"))
                        object.previousOutput = $root.TW.proto.BitcoinOutPoint.toObject(message.previousOutput, options);
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        object.sequence = message.sequence;
                    if (message.script != null && message.hasOwnProperty("script"))
                        object.script = options.bytes === String ? $util.base64.encode(message.script, 0, message.script.length) : options.bytes === Array ? Array.prototype.slice.call(message.script) : message.script;
                    return object;
                };
    
                /**
                 * Converts this BitcoinTransactionInput to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinTransactionInput
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinTransactionInput.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinTransactionInput;
            })();
    
            proto.BitcoinOutPoint = (function() {
    
                /**
                 * Properties of a BitcoinOutPoint.
                 * @memberof TW.proto
                 * @interface IBitcoinOutPoint
                 * @property {Uint8Array|null} [hash] BitcoinOutPoint hash
                 * @property {number|null} [index] BitcoinOutPoint index
                 * @property {number|null} [sequence] BitcoinOutPoint sequence
                 */
    
                /**
                 * Constructs a new BitcoinOutPoint.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinOutPoint.
                 * @implements IBitcoinOutPoint
                 * @constructor
                 * @param {TW.proto.IBitcoinOutPoint=} [properties] Properties to set
                 */
                function BitcoinOutPoint(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinOutPoint hash.
                 * @member {Uint8Array} hash
                 * @memberof TW.proto.BitcoinOutPoint
                 * @instance
                 */
                BitcoinOutPoint.prototype.hash = $util.newBuffer([]);
    
                /**
                 * BitcoinOutPoint index.
                 * @member {number} index
                 * @memberof TW.proto.BitcoinOutPoint
                 * @instance
                 */
                BitcoinOutPoint.prototype.index = 0;
    
                /**
                 * BitcoinOutPoint sequence.
                 * @member {number} sequence
                 * @memberof TW.proto.BitcoinOutPoint
                 * @instance
                 */
                BitcoinOutPoint.prototype.sequence = 0;
    
                /**
                 * Creates a new BitcoinOutPoint instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {TW.proto.IBitcoinOutPoint=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinOutPoint} BitcoinOutPoint instance
                 */
                BitcoinOutPoint.create = function create(properties) {
                    return new BitcoinOutPoint(properties);
                };
    
                /**
                 * Encodes the specified BitcoinOutPoint message. Does not implicitly {@link TW.proto.BitcoinOutPoint.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {TW.proto.IBitcoinOutPoint} message BitcoinOutPoint message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinOutPoint.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.hash != null && message.hasOwnProperty("hash"))
                        writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.hash);
                    if (message.index != null && message.hasOwnProperty("index"))
                        writer.uint32(/* id 2, wireType 0 =*/16).uint32(message.index);
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        writer.uint32(/* id 3, wireType 0 =*/24).uint32(message.sequence);
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinOutPoint message, length delimited. Does not implicitly {@link TW.proto.BitcoinOutPoint.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {TW.proto.IBitcoinOutPoint} message BitcoinOutPoint message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinOutPoint.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinOutPoint message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinOutPoint} BitcoinOutPoint
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinOutPoint.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinOutPoint();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.hash = reader.bytes();
                            break;
                        case 2:
                            message.index = reader.uint32();
                            break;
                        case 3:
                            message.sequence = reader.uint32();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinOutPoint message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinOutPoint} BitcoinOutPoint
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinOutPoint.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinOutPoint message.
                 * @function verify
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinOutPoint.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.hash != null && message.hasOwnProperty("hash"))
                        if (!(message.hash && typeof message.hash.length === "number" || $util.isString(message.hash)))
                            return "hash: buffer expected";
                    if (message.index != null && message.hasOwnProperty("index"))
                        if (!$util.isInteger(message.index))
                            return "index: integer expected";
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        if (!$util.isInteger(message.sequence))
                            return "sequence: integer expected";
                    return null;
                };
    
                /**
                 * Creates a BitcoinOutPoint message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinOutPoint} BitcoinOutPoint
                 */
                BitcoinOutPoint.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinOutPoint)
                        return object;
                    var message = new $root.TW.proto.BitcoinOutPoint();
                    if (object.hash != null)
                        if (typeof object.hash === "string")
                            $util.base64.decode(object.hash, message.hash = $util.newBuffer($util.base64.length(object.hash)), 0);
                        else if (object.hash.length)
                            message.hash = object.hash;
                    if (object.index != null)
                        message.index = object.index >>> 0;
                    if (object.sequence != null)
                        message.sequence = object.sequence >>> 0;
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinOutPoint message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinOutPoint
                 * @static
                 * @param {TW.proto.BitcoinOutPoint} message BitcoinOutPoint
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinOutPoint.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if (options.bytes === String)
                            object.hash = "";
                        else {
                            object.hash = [];
                            if (options.bytes !== Array)
                                object.hash = $util.newBuffer(object.hash);
                        }
                        object.index = 0;
                        object.sequence = 0;
                    }
                    if (message.hash != null && message.hasOwnProperty("hash"))
                        object.hash = options.bytes === String ? $util.base64.encode(message.hash, 0, message.hash.length) : options.bytes === Array ? Array.prototype.slice.call(message.hash) : message.hash;
                    if (message.index != null && message.hasOwnProperty("index"))
                        object.index = message.index;
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        object.sequence = message.sequence;
                    return object;
                };
    
                /**
                 * Converts this BitcoinOutPoint to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinOutPoint
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinOutPoint.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinOutPoint;
            })();
    
            proto.BitcoinTransactionOutput = (function() {
    
                /**
                 * Properties of a BitcoinTransactionOutput.
                 * @memberof TW.proto
                 * @interface IBitcoinTransactionOutput
                 * @property {Long|null} [value] BitcoinTransactionOutput value
                 * @property {Uint8Array|null} [script] BitcoinTransactionOutput script
                 */
    
                /**
                 * Constructs a new BitcoinTransactionOutput.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinTransactionOutput.
                 * @implements IBitcoinTransactionOutput
                 * @constructor
                 * @param {TW.proto.IBitcoinTransactionOutput=} [properties] Properties to set
                 */
                function BitcoinTransactionOutput(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinTransactionOutput value.
                 * @member {Long} value
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @instance
                 */
                BitcoinTransactionOutput.prototype.value = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BitcoinTransactionOutput script.
                 * @member {Uint8Array} script
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @instance
                 */
                BitcoinTransactionOutput.prototype.script = $util.newBuffer([]);
    
                /**
                 * Creates a new BitcoinTransactionOutput instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {TW.proto.IBitcoinTransactionOutput=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinTransactionOutput} BitcoinTransactionOutput instance
                 */
                BitcoinTransactionOutput.create = function create(properties) {
                    return new BitcoinTransactionOutput(properties);
                };
    
                /**
                 * Encodes the specified BitcoinTransactionOutput message. Does not implicitly {@link TW.proto.BitcoinTransactionOutput.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {TW.proto.IBitcoinTransactionOutput} message BitcoinTransactionOutput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinTransactionOutput.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.value != null && message.hasOwnProperty("value"))
                        writer.uint32(/* id 1, wireType 0 =*/8).int64(message.value);
                    if (message.script != null && message.hasOwnProperty("script"))
                        writer.uint32(/* id 2, wireType 2 =*/18).bytes(message.script);
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinTransactionOutput message, length delimited. Does not implicitly {@link TW.proto.BitcoinTransactionOutput.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {TW.proto.IBitcoinTransactionOutput} message BitcoinTransactionOutput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinTransactionOutput.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinTransactionOutput message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinTransactionOutput} BitcoinTransactionOutput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinTransactionOutput.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinTransactionOutput();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.value = reader.int64();
                            break;
                        case 2:
                            message.script = reader.bytes();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinTransactionOutput message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinTransactionOutput} BitcoinTransactionOutput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinTransactionOutput.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinTransactionOutput message.
                 * @function verify
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinTransactionOutput.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.value != null && message.hasOwnProperty("value"))
                        if (!$util.isInteger(message.value) && !(message.value && $util.isInteger(message.value.low) && $util.isInteger(message.value.high)))
                            return "value: integer|Long expected";
                    if (message.script != null && message.hasOwnProperty("script"))
                        if (!(message.script && typeof message.script.length === "number" || $util.isString(message.script)))
                            return "script: buffer expected";
                    return null;
                };
    
                /**
                 * Creates a BitcoinTransactionOutput message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinTransactionOutput} BitcoinTransactionOutput
                 */
                BitcoinTransactionOutput.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinTransactionOutput)
                        return object;
                    var message = new $root.TW.proto.BitcoinTransactionOutput();
                    if (object.value != null)
                        if ($util.Long)
                            (message.value = $util.Long.fromValue(object.value)).unsigned = false;
                        else if (typeof object.value === "string")
                            message.value = parseInt(object.value, 10);
                        else if (typeof object.value === "number")
                            message.value = object.value;
                        else if (typeof object.value === "object")
                            message.value = new $util.LongBits(object.value.low >>> 0, object.value.high >>> 0).toNumber();
                    if (object.script != null)
                        if (typeof object.script === "string")
                            $util.base64.decode(object.script, message.script = $util.newBuffer($util.base64.length(object.script)), 0);
                        else if (object.script.length)
                            message.script = object.script;
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinTransactionOutput message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @static
                 * @param {TW.proto.BitcoinTransactionOutput} message BitcoinTransactionOutput
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinTransactionOutput.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.value = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.value = options.longs === String ? "0" : 0;
                        if (options.bytes === String)
                            object.script = "";
                        else {
                            object.script = [];
                            if (options.bytes !== Array)
                                object.script = $util.newBuffer(object.script);
                        }
                    }
                    if (message.value != null && message.hasOwnProperty("value"))
                        if (typeof message.value === "number")
                            object.value = options.longs === String ? String(message.value) : message.value;
                        else
                            object.value = options.longs === String ? $util.Long.prototype.toString.call(message.value) : options.longs === Number ? new $util.LongBits(message.value.low >>> 0, message.value.high >>> 0).toNumber() : message.value;
                    if (message.script != null && message.hasOwnProperty("script"))
                        object.script = options.bytes === String ? $util.base64.encode(message.script, 0, message.script.length) : options.bytes === Array ? Array.prototype.slice.call(message.script) : message.script;
                    return object;
                };
    
                /**
                 * Converts this BitcoinTransactionOutput to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinTransactionOutput
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinTransactionOutput.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinTransactionOutput;
            })();
    
            proto.BitcoinUnspentTransaction = (function() {
    
                /**
                 * Properties of a BitcoinUnspentTransaction.
                 * @memberof TW.proto
                 * @interface IBitcoinUnspentTransaction
                 * @property {TW.proto.IBitcoinOutPoint|null} [outPoint] BitcoinUnspentTransaction outPoint
                 * @property {Uint8Array|null} [script] BitcoinUnspentTransaction script
                 * @property {Long|null} [amount] BitcoinUnspentTransaction amount
                 */
    
                /**
                 * Constructs a new BitcoinUnspentTransaction.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinUnspentTransaction.
                 * @implements IBitcoinUnspentTransaction
                 * @constructor
                 * @param {TW.proto.IBitcoinUnspentTransaction=} [properties] Properties to set
                 */
                function BitcoinUnspentTransaction(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinUnspentTransaction outPoint.
                 * @member {TW.proto.IBitcoinOutPoint|null|undefined} outPoint
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @instance
                 */
                BitcoinUnspentTransaction.prototype.outPoint = null;
    
                /**
                 * BitcoinUnspentTransaction script.
                 * @member {Uint8Array} script
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @instance
                 */
                BitcoinUnspentTransaction.prototype.script = $util.newBuffer([]);
    
                /**
                 * BitcoinUnspentTransaction amount.
                 * @member {Long} amount
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @instance
                 */
                BitcoinUnspentTransaction.prototype.amount = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * Creates a new BitcoinUnspentTransaction instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {TW.proto.IBitcoinUnspentTransaction=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinUnspentTransaction} BitcoinUnspentTransaction instance
                 */
                BitcoinUnspentTransaction.create = function create(properties) {
                    return new BitcoinUnspentTransaction(properties);
                };
    
                /**
                 * Encodes the specified BitcoinUnspentTransaction message. Does not implicitly {@link TW.proto.BitcoinUnspentTransaction.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {TW.proto.IBitcoinUnspentTransaction} message BitcoinUnspentTransaction message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinUnspentTransaction.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.outPoint != null && message.hasOwnProperty("outPoint"))
                        $root.TW.proto.BitcoinOutPoint.encode(message.outPoint, writer.uint32(/* id 1, wireType 2 =*/10).fork()).ldelim();
                    if (message.script != null && message.hasOwnProperty("script"))
                        writer.uint32(/* id 2, wireType 2 =*/18).bytes(message.script);
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        writer.uint32(/* id 3, wireType 0 =*/24).int64(message.amount);
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinUnspentTransaction message, length delimited. Does not implicitly {@link TW.proto.BitcoinUnspentTransaction.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {TW.proto.IBitcoinUnspentTransaction} message BitcoinUnspentTransaction message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinUnspentTransaction.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinUnspentTransaction message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinUnspentTransaction} BitcoinUnspentTransaction
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinUnspentTransaction.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinUnspentTransaction();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.outPoint = $root.TW.proto.BitcoinOutPoint.decode(reader, reader.uint32());
                            break;
                        case 2:
                            message.script = reader.bytes();
                            break;
                        case 3:
                            message.amount = reader.int64();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinUnspentTransaction message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinUnspentTransaction} BitcoinUnspentTransaction
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinUnspentTransaction.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinUnspentTransaction message.
                 * @function verify
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinUnspentTransaction.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.outPoint != null && message.hasOwnProperty("outPoint")) {
                        var error = $root.TW.proto.BitcoinOutPoint.verify(message.outPoint);
                        if (error)
                            return "outPoint." + error;
                    }
                    if (message.script != null && message.hasOwnProperty("script"))
                        if (!(message.script && typeof message.script.length === "number" || $util.isString(message.script)))
                            return "script: buffer expected";
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (!$util.isInteger(message.amount) && !(message.amount && $util.isInteger(message.amount.low) && $util.isInteger(message.amount.high)))
                            return "amount: integer|Long expected";
                    return null;
                };
    
                /**
                 * Creates a BitcoinUnspentTransaction message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinUnspentTransaction} BitcoinUnspentTransaction
                 */
                BitcoinUnspentTransaction.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinUnspentTransaction)
                        return object;
                    var message = new $root.TW.proto.BitcoinUnspentTransaction();
                    if (object.outPoint != null) {
                        if (typeof object.outPoint !== "object")
                            throw TypeError(".TW.proto.BitcoinUnspentTransaction.outPoint: object expected");
                        message.outPoint = $root.TW.proto.BitcoinOutPoint.fromObject(object.outPoint);
                    }
                    if (object.script != null)
                        if (typeof object.script === "string")
                            $util.base64.decode(object.script, message.script = $util.newBuffer($util.base64.length(object.script)), 0);
                        else if (object.script.length)
                            message.script = object.script;
                    if (object.amount != null)
                        if ($util.Long)
                            (message.amount = $util.Long.fromValue(object.amount)).unsigned = false;
                        else if (typeof object.amount === "string")
                            message.amount = parseInt(object.amount, 10);
                        else if (typeof object.amount === "number")
                            message.amount = object.amount;
                        else if (typeof object.amount === "object")
                            message.amount = new $util.LongBits(object.amount.low >>> 0, object.amount.high >>> 0).toNumber();
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinUnspentTransaction message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @static
                 * @param {TW.proto.BitcoinUnspentTransaction} message BitcoinUnspentTransaction
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinUnspentTransaction.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        object.outPoint = null;
                        if (options.bytes === String)
                            object.script = "";
                        else {
                            object.script = [];
                            if (options.bytes !== Array)
                                object.script = $util.newBuffer(object.script);
                        }
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.amount = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.amount = options.longs === String ? "0" : 0;
                    }
                    if (message.outPoint != null && message.hasOwnProperty("outPoint"))
                        object.outPoint = $root.TW.proto.BitcoinOutPoint.toObject(message.outPoint, options);
                    if (message.script != null && message.hasOwnProperty("script"))
                        object.script = options.bytes === String ? $util.base64.encode(message.script, 0, message.script.length) : options.bytes === Array ? Array.prototype.slice.call(message.script) : message.script;
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (typeof message.amount === "number")
                            object.amount = options.longs === String ? String(message.amount) : message.amount;
                        else
                            object.amount = options.longs === String ? $util.Long.prototype.toString.call(message.amount) : options.longs === Number ? new $util.LongBits(message.amount.low >>> 0, message.amount.high >>> 0).toNumber() : message.amount;
                    return object;
                };
    
                /**
                 * Converts this BitcoinUnspentTransaction to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinUnspentTransaction
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinUnspentTransaction.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinUnspentTransaction;
            })();
    
            proto.BitcoinSigningInput = (function() {
    
                /**
                 * Properties of a BitcoinSigningInput.
                 * @memberof TW.proto
                 * @interface IBitcoinSigningInput
                 * @property {number|null} [hashType] BitcoinSigningInput hashType
                 * @property {Long|null} [amount] BitcoinSigningInput amount
                 * @property {Long|null} [byteFee] BitcoinSigningInput byteFee
                 * @property {string|null} [toAddress] BitcoinSigningInput toAddress
                 * @property {string|null} [changeAddress] BitcoinSigningInput changeAddress
                 * @property {Array.<Uint8Array>|null} [privateKey] BitcoinSigningInput privateKey
                 * @property {Object.<string,Uint8Array>|null} [scripts] BitcoinSigningInput scripts
                 * @property {Array.<TW.proto.IBitcoinUnspentTransaction>|null} [utxo] BitcoinSigningInput utxo
                 */
    
                /**
                 * Constructs a new BitcoinSigningInput.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinSigningInput.
                 * @implements IBitcoinSigningInput
                 * @constructor
                 * @param {TW.proto.IBitcoinSigningInput=} [properties] Properties to set
                 */
                function BitcoinSigningInput(properties) {
                    this.privateKey = [];
                    this.scripts = {};
                    this.utxo = [];
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinSigningInput hashType.
                 * @member {number} hashType
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.hashType = 0;
    
                /**
                 * BitcoinSigningInput amount.
                 * @member {Long} amount
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.amount = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BitcoinSigningInput byteFee.
                 * @member {Long} byteFee
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.byteFee = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BitcoinSigningInput toAddress.
                 * @member {string} toAddress
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.toAddress = "";
    
                /**
                 * BitcoinSigningInput changeAddress.
                 * @member {string} changeAddress
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.changeAddress = "";
    
                /**
                 * BitcoinSigningInput privateKey.
                 * @member {Array.<Uint8Array>} privateKey
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.privateKey = $util.emptyArray;
    
                /**
                 * BitcoinSigningInput scripts.
                 * @member {Object.<string,Uint8Array>} scripts
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.scripts = $util.emptyObject;
    
                /**
                 * BitcoinSigningInput utxo.
                 * @member {Array.<TW.proto.IBitcoinUnspentTransaction>} utxo
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 */
                BitcoinSigningInput.prototype.utxo = $util.emptyArray;
    
                /**
                 * Creates a new BitcoinSigningInput instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {TW.proto.IBitcoinSigningInput=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinSigningInput} BitcoinSigningInput instance
                 */
                BitcoinSigningInput.create = function create(properties) {
                    return new BitcoinSigningInput(properties);
                };
    
                /**
                 * Encodes the specified BitcoinSigningInput message. Does not implicitly {@link TW.proto.BitcoinSigningInput.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {TW.proto.IBitcoinSigningInput} message BitcoinSigningInput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinSigningInput.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.hashType != null && message.hasOwnProperty("hashType"))
                        writer.uint32(/* id 1, wireType 0 =*/8).uint32(message.hashType);
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        writer.uint32(/* id 2, wireType 0 =*/16).int64(message.amount);
                    if (message.byteFee != null && message.hasOwnProperty("byteFee"))
                        writer.uint32(/* id 3, wireType 0 =*/24).int64(message.byteFee);
                    if (message.toAddress != null && message.hasOwnProperty("toAddress"))
                        writer.uint32(/* id 4, wireType 2 =*/34).string(message.toAddress);
                    if (message.changeAddress != null && message.hasOwnProperty("changeAddress"))
                        writer.uint32(/* id 5, wireType 2 =*/42).string(message.changeAddress);
                    if (message.privateKey != null && message.privateKey.length)
                        for (var i = 0; i < message.privateKey.length; ++i)
                            writer.uint32(/* id 10, wireType 2 =*/82).bytes(message.privateKey[i]);
                    if (message.scripts != null && message.hasOwnProperty("scripts"))
                        for (var keys = Object.keys(message.scripts), i = 0; i < keys.length; ++i)
                            writer.uint32(/* id 11, wireType 2 =*/90).fork().uint32(/* id 1, wireType 2 =*/10).string(keys[i]).uint32(/* id 2, wireType 2 =*/18).bytes(message.scripts[keys[i]]).ldelim();
                    if (message.utxo != null && message.utxo.length)
                        for (var i = 0; i < message.utxo.length; ++i)
                            $root.TW.proto.BitcoinUnspentTransaction.encode(message.utxo[i], writer.uint32(/* id 12, wireType 2 =*/98).fork()).ldelim();
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinSigningInput message, length delimited. Does not implicitly {@link TW.proto.BitcoinSigningInput.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {TW.proto.IBitcoinSigningInput} message BitcoinSigningInput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinSigningInput.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinSigningInput message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinSigningInput} BitcoinSigningInput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinSigningInput.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinSigningInput(), key;
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.hashType = reader.uint32();
                            break;
                        case 2:
                            message.amount = reader.int64();
                            break;
                        case 3:
                            message.byteFee = reader.int64();
                            break;
                        case 4:
                            message.toAddress = reader.string();
                            break;
                        case 5:
                            message.changeAddress = reader.string();
                            break;
                        case 10:
                            if (!(message.privateKey && message.privateKey.length))
                                message.privateKey = [];
                            message.privateKey.push(reader.bytes());
                            break;
                        case 11:
                            reader.skip().pos++;
                            if (message.scripts === $util.emptyObject)
                                message.scripts = {};
                            key = reader.string();
                            reader.pos++;
                            message.scripts[key] = reader.bytes();
                            break;
                        case 12:
                            if (!(message.utxo && message.utxo.length))
                                message.utxo = [];
                            message.utxo.push($root.TW.proto.BitcoinUnspentTransaction.decode(reader, reader.uint32()));
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinSigningInput message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinSigningInput} BitcoinSigningInput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinSigningInput.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinSigningInput message.
                 * @function verify
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinSigningInput.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.hashType != null && message.hasOwnProperty("hashType"))
                        if (!$util.isInteger(message.hashType))
                            return "hashType: integer expected";
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (!$util.isInteger(message.amount) && !(message.amount && $util.isInteger(message.amount.low) && $util.isInteger(message.amount.high)))
                            return "amount: integer|Long expected";
                    if (message.byteFee != null && message.hasOwnProperty("byteFee"))
                        if (!$util.isInteger(message.byteFee) && !(message.byteFee && $util.isInteger(message.byteFee.low) && $util.isInteger(message.byteFee.high)))
                            return "byteFee: integer|Long expected";
                    if (message.toAddress != null && message.hasOwnProperty("toAddress"))
                        if (!$util.isString(message.toAddress))
                            return "toAddress: string expected";
                    if (message.changeAddress != null && message.hasOwnProperty("changeAddress"))
                        if (!$util.isString(message.changeAddress))
                            return "changeAddress: string expected";
                    if (message.privateKey != null && message.hasOwnProperty("privateKey")) {
                        if (!Array.isArray(message.privateKey))
                            return "privateKey: array expected";
                        for (var i = 0; i < message.privateKey.length; ++i)
                            if (!(message.privateKey[i] && typeof message.privateKey[i].length === "number" || $util.isString(message.privateKey[i])))
                                return "privateKey: buffer[] expected";
                    }
                    if (message.scripts != null && message.hasOwnProperty("scripts")) {
                        if (!$util.isObject(message.scripts))
                            return "scripts: object expected";
                        var key = Object.keys(message.scripts);
                        for (var i = 0; i < key.length; ++i)
                            if (!(message.scripts[key[i]] && typeof message.scripts[key[i]].length === "number" || $util.isString(message.scripts[key[i]])))
                                return "scripts: buffer{k:string} expected";
                    }
                    if (message.utxo != null && message.hasOwnProperty("utxo")) {
                        if (!Array.isArray(message.utxo))
                            return "utxo: array expected";
                        for (var i = 0; i < message.utxo.length; ++i) {
                            var error = $root.TW.proto.BitcoinUnspentTransaction.verify(message.utxo[i]);
                            if (error)
                                return "utxo." + error;
                        }
                    }
                    return null;
                };
    
                /**
                 * Creates a BitcoinSigningInput message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinSigningInput} BitcoinSigningInput
                 */
                BitcoinSigningInput.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinSigningInput)
                        return object;
                    var message = new $root.TW.proto.BitcoinSigningInput();
                    if (object.hashType != null)
                        message.hashType = object.hashType >>> 0;
                    if (object.amount != null)
                        if ($util.Long)
                            (message.amount = $util.Long.fromValue(object.amount)).unsigned = false;
                        else if (typeof object.amount === "string")
                            message.amount = parseInt(object.amount, 10);
                        else if (typeof object.amount === "number")
                            message.amount = object.amount;
                        else if (typeof object.amount === "object")
                            message.amount = new $util.LongBits(object.amount.low >>> 0, object.amount.high >>> 0).toNumber();
                    if (object.byteFee != null)
                        if ($util.Long)
                            (message.byteFee = $util.Long.fromValue(object.byteFee)).unsigned = false;
                        else if (typeof object.byteFee === "string")
                            message.byteFee = parseInt(object.byteFee, 10);
                        else if (typeof object.byteFee === "number")
                            message.byteFee = object.byteFee;
                        else if (typeof object.byteFee === "object")
                            message.byteFee = new $util.LongBits(object.byteFee.low >>> 0, object.byteFee.high >>> 0).toNumber();
                    if (object.toAddress != null)
                        message.toAddress = String(object.toAddress);
                    if (object.changeAddress != null)
                        message.changeAddress = String(object.changeAddress);
                    if (object.privateKey) {
                        if (!Array.isArray(object.privateKey))
                            throw TypeError(".TW.proto.BitcoinSigningInput.privateKey: array expected");
                        message.privateKey = [];
                        for (var i = 0; i < object.privateKey.length; ++i)
                            if (typeof object.privateKey[i] === "string")
                                $util.base64.decode(object.privateKey[i], message.privateKey[i] = $util.newBuffer($util.base64.length(object.privateKey[i])), 0);
                            else if (object.privateKey[i].length)
                                message.privateKey[i] = object.privateKey[i];
                    }
                    if (object.scripts) {
                        if (typeof object.scripts !== "object")
                            throw TypeError(".TW.proto.BitcoinSigningInput.scripts: object expected");
                        message.scripts = {};
                        for (var keys = Object.keys(object.scripts), i = 0; i < keys.length; ++i)
                            if (typeof object.scripts[keys[i]] === "string")
                                $util.base64.decode(object.scripts[keys[i]], message.scripts[keys[i]] = $util.newBuffer($util.base64.length(object.scripts[keys[i]])), 0);
                            else if (object.scripts[keys[i]].length)
                                message.scripts[keys[i]] = object.scripts[keys[i]];
                    }
                    if (object.utxo) {
                        if (!Array.isArray(object.utxo))
                            throw TypeError(".TW.proto.BitcoinSigningInput.utxo: array expected");
                        message.utxo = [];
                        for (var i = 0; i < object.utxo.length; ++i) {
                            if (typeof object.utxo[i] !== "object")
                                throw TypeError(".TW.proto.BitcoinSigningInput.utxo: object expected");
                            message.utxo[i] = $root.TW.proto.BitcoinUnspentTransaction.fromObject(object.utxo[i]);
                        }
                    }
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinSigningInput message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinSigningInput
                 * @static
                 * @param {TW.proto.BitcoinSigningInput} message BitcoinSigningInput
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinSigningInput.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.arrays || options.defaults) {
                        object.privateKey = [];
                        object.utxo = [];
                    }
                    if (options.objects || options.defaults)
                        object.scripts = {};
                    if (options.defaults) {
                        object.hashType = 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.amount = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.amount = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.byteFee = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.byteFee = options.longs === String ? "0" : 0;
                        object.toAddress = "";
                        object.changeAddress = "";
                    }
                    if (message.hashType != null && message.hasOwnProperty("hashType"))
                        object.hashType = message.hashType;
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (typeof message.amount === "number")
                            object.amount = options.longs === String ? String(message.amount) : message.amount;
                        else
                            object.amount = options.longs === String ? $util.Long.prototype.toString.call(message.amount) : options.longs === Number ? new $util.LongBits(message.amount.low >>> 0, message.amount.high >>> 0).toNumber() : message.amount;
                    if (message.byteFee != null && message.hasOwnProperty("byteFee"))
                        if (typeof message.byteFee === "number")
                            object.byteFee = options.longs === String ? String(message.byteFee) : message.byteFee;
                        else
                            object.byteFee = options.longs === String ? $util.Long.prototype.toString.call(message.byteFee) : options.longs === Number ? new $util.LongBits(message.byteFee.low >>> 0, message.byteFee.high >>> 0).toNumber() : message.byteFee;
                    if (message.toAddress != null && message.hasOwnProperty("toAddress"))
                        object.toAddress = message.toAddress;
                    if (message.changeAddress != null && message.hasOwnProperty("changeAddress"))
                        object.changeAddress = message.changeAddress;
                    if (message.privateKey && message.privateKey.length) {
                        object.privateKey = [];
                        for (var j = 0; j < message.privateKey.length; ++j)
                            object.privateKey[j] = options.bytes === String ? $util.base64.encode(message.privateKey[j], 0, message.privateKey[j].length) : options.bytes === Array ? Array.prototype.slice.call(message.privateKey[j]) : message.privateKey[j];
                    }
                    var keys2;
                    if (message.scripts && (keys2 = Object.keys(message.scripts)).length) {
                        object.scripts = {};
                        for (var j = 0; j < keys2.length; ++j)
                            object.scripts[keys2[j]] = options.bytes === String ? $util.base64.encode(message.scripts[keys2[j]], 0, message.scripts[keys2[j]].length) : options.bytes === Array ? Array.prototype.slice.call(message.scripts[keys2[j]]) : message.scripts[keys2[j]];
                    }
                    if (message.utxo && message.utxo.length) {
                        object.utxo = [];
                        for (var j = 0; j < message.utxo.length; ++j)
                            object.utxo[j] = $root.TW.proto.BitcoinUnspentTransaction.toObject(message.utxo[j], options);
                    }
                    return object;
                };
    
                /**
                 * Converts this BitcoinSigningInput to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinSigningInput
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinSigningInput.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinSigningInput;
            })();
    
            proto.BitcoinSigningOutput = (function() {
    
                /**
                 * Properties of a BitcoinSigningOutput.
                 * @memberof TW.proto
                 * @interface IBitcoinSigningOutput
                 * @property {TW.proto.IBitcoinTransaction|null} [transaction] BitcoinSigningOutput transaction
                 * @property {Uint8Array|null} [encoded] BitcoinSigningOutput encoded
                 */
    
                /**
                 * Constructs a new BitcoinSigningOutput.
                 * @memberof TW.proto
                 * @classdesc Represents a BitcoinSigningOutput.
                 * @implements IBitcoinSigningOutput
                 * @constructor
                 * @param {TW.proto.IBitcoinSigningOutput=} [properties] Properties to set
                 */
                function BitcoinSigningOutput(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BitcoinSigningOutput transaction.
                 * @member {TW.proto.IBitcoinTransaction|null|undefined} transaction
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @instance
                 */
                BitcoinSigningOutput.prototype.transaction = null;
    
                /**
                 * BitcoinSigningOutput encoded.
                 * @member {Uint8Array} encoded
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @instance
                 */
                BitcoinSigningOutput.prototype.encoded = $util.newBuffer([]);
    
                /**
                 * Creates a new BitcoinSigningOutput instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {TW.proto.IBitcoinSigningOutput=} [properties] Properties to set
                 * @returns {TW.proto.BitcoinSigningOutput} BitcoinSigningOutput instance
                 */
                BitcoinSigningOutput.create = function create(properties) {
                    return new BitcoinSigningOutput(properties);
                };
    
                /**
                 * Encodes the specified BitcoinSigningOutput message. Does not implicitly {@link TW.proto.BitcoinSigningOutput.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {TW.proto.IBitcoinSigningOutput} message BitcoinSigningOutput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinSigningOutput.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.transaction != null && message.hasOwnProperty("transaction"))
                        $root.TW.proto.BitcoinTransaction.encode(message.transaction, writer.uint32(/* id 1, wireType 2 =*/10).fork()).ldelim();
                    if (message.encoded != null && message.hasOwnProperty("encoded"))
                        writer.uint32(/* id 2, wireType 2 =*/18).bytes(message.encoded);
                    return writer;
                };
    
                /**
                 * Encodes the specified BitcoinSigningOutput message, length delimited. Does not implicitly {@link TW.proto.BitcoinSigningOutput.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {TW.proto.IBitcoinSigningOutput} message BitcoinSigningOutput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BitcoinSigningOutput.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BitcoinSigningOutput message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BitcoinSigningOutput} BitcoinSigningOutput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinSigningOutput.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BitcoinSigningOutput();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.transaction = $root.TW.proto.BitcoinTransaction.decode(reader, reader.uint32());
                            break;
                        case 2:
                            message.encoded = reader.bytes();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BitcoinSigningOutput message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BitcoinSigningOutput} BitcoinSigningOutput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BitcoinSigningOutput.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BitcoinSigningOutput message.
                 * @function verify
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BitcoinSigningOutput.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.transaction != null && message.hasOwnProperty("transaction")) {
                        var error = $root.TW.proto.BitcoinTransaction.verify(message.transaction);
                        if (error)
                            return "transaction." + error;
                    }
                    if (message.encoded != null && message.hasOwnProperty("encoded"))
                        if (!(message.encoded && typeof message.encoded.length === "number" || $util.isString(message.encoded)))
                            return "encoded: buffer expected";
                    return null;
                };
    
                /**
                 * Creates a BitcoinSigningOutput message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BitcoinSigningOutput} BitcoinSigningOutput
                 */
                BitcoinSigningOutput.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BitcoinSigningOutput)
                        return object;
                    var message = new $root.TW.proto.BitcoinSigningOutput();
                    if (object.transaction != null) {
                        if (typeof object.transaction !== "object")
                            throw TypeError(".TW.proto.BitcoinSigningOutput.transaction: object expected");
                        message.transaction = $root.TW.proto.BitcoinTransaction.fromObject(object.transaction);
                    }
                    if (object.encoded != null)
                        if (typeof object.encoded === "string")
                            $util.base64.decode(object.encoded, message.encoded = $util.newBuffer($util.base64.length(object.encoded)), 0);
                        else if (object.encoded.length)
                            message.encoded = object.encoded;
                    return message;
                };
    
                /**
                 * Creates a plain object from a BitcoinSigningOutput message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @static
                 * @param {TW.proto.BitcoinSigningOutput} message BitcoinSigningOutput
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BitcoinSigningOutput.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        object.transaction = null;
                        if (options.bytes === String)
                            object.encoded = "";
                        else {
                            object.encoded = [];
                            if (options.bytes !== Array)
                                object.encoded = $util.newBuffer(object.encoded);
                        }
                    }
                    if (message.transaction != null && message.hasOwnProperty("transaction"))
                        object.transaction = $root.TW.proto.BitcoinTransaction.toObject(message.transaction, options);
                    if (message.encoded != null && message.hasOwnProperty("encoded"))
                        object.encoded = options.bytes === String ? $util.base64.encode(message.encoded, 0, message.encoded.length) : options.bytes === Array ? Array.prototype.slice.call(message.encoded) : message.encoded;
                    return object;
                };
    
                /**
                 * Converts this BitcoinSigningOutput to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BitcoinSigningOutput
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BitcoinSigningOutput.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BitcoinSigningOutput;
            })();
    
            proto.BinanceTransaction = (function() {
    
                /**
                 * Properties of a BinanceTransaction.
                 * @memberof TW.proto
                 * @interface IBinanceTransaction
                 * @property {Array.<Uint8Array>|null} [msgs] BinanceTransaction msgs
                 * @property {Array.<Uint8Array>|null} [signatures] BinanceTransaction signatures
                 * @property {string|null} [memo] BinanceTransaction memo
                 * @property {Long|null} [source] BinanceTransaction source
                 * @property {Uint8Array|null} [data] BinanceTransaction data
                 */
    
                /**
                 * Constructs a new BinanceTransaction.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceTransaction.
                 * @implements IBinanceTransaction
                 * @constructor
                 * @param {TW.proto.IBinanceTransaction=} [properties] Properties to set
                 */
                function BinanceTransaction(properties) {
                    this.msgs = [];
                    this.signatures = [];
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceTransaction msgs.
                 * @member {Array.<Uint8Array>} msgs
                 * @memberof TW.proto.BinanceTransaction
                 * @instance
                 */
                BinanceTransaction.prototype.msgs = $util.emptyArray;
    
                /**
                 * BinanceTransaction signatures.
                 * @member {Array.<Uint8Array>} signatures
                 * @memberof TW.proto.BinanceTransaction
                 * @instance
                 */
                BinanceTransaction.prototype.signatures = $util.emptyArray;
    
                /**
                 * BinanceTransaction memo.
                 * @member {string} memo
                 * @memberof TW.proto.BinanceTransaction
                 * @instance
                 */
                BinanceTransaction.prototype.memo = "";
    
                /**
                 * BinanceTransaction source.
                 * @member {Long} source
                 * @memberof TW.proto.BinanceTransaction
                 * @instance
                 */
                BinanceTransaction.prototype.source = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceTransaction data.
                 * @member {Uint8Array} data
                 * @memberof TW.proto.BinanceTransaction
                 * @instance
                 */
                BinanceTransaction.prototype.data = $util.newBuffer([]);
    
                /**
                 * Creates a new BinanceTransaction instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {TW.proto.IBinanceTransaction=} [properties] Properties to set
                 * @returns {TW.proto.BinanceTransaction} BinanceTransaction instance
                 */
                BinanceTransaction.create = function create(properties) {
                    return new BinanceTransaction(properties);
                };
    
                /**
                 * Encodes the specified BinanceTransaction message. Does not implicitly {@link TW.proto.BinanceTransaction.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {TW.proto.IBinanceTransaction} message BinanceTransaction message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTransaction.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.msgs != null && message.msgs.length)
                        for (var i = 0; i < message.msgs.length; ++i)
                            writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.msgs[i]);
                    if (message.signatures != null && message.signatures.length)
                        for (var i = 0; i < message.signatures.length; ++i)
                            writer.uint32(/* id 2, wireType 2 =*/18).bytes(message.signatures[i]);
                    if (message.memo != null && message.hasOwnProperty("memo"))
                        writer.uint32(/* id 3, wireType 2 =*/26).string(message.memo);
                    if (message.source != null && message.hasOwnProperty("source"))
                        writer.uint32(/* id 4, wireType 0 =*/32).int64(message.source);
                    if (message.data != null && message.hasOwnProperty("data"))
                        writer.uint32(/* id 5, wireType 2 =*/42).bytes(message.data);
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceTransaction message, length delimited. Does not implicitly {@link TW.proto.BinanceTransaction.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {TW.proto.IBinanceTransaction} message BinanceTransaction message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTransaction.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceTransaction message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceTransaction} BinanceTransaction
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTransaction.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceTransaction();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            if (!(message.msgs && message.msgs.length))
                                message.msgs = [];
                            message.msgs.push(reader.bytes());
                            break;
                        case 2:
                            if (!(message.signatures && message.signatures.length))
                                message.signatures = [];
                            message.signatures.push(reader.bytes());
                            break;
                        case 3:
                            message.memo = reader.string();
                            break;
                        case 4:
                            message.source = reader.int64();
                            break;
                        case 5:
                            message.data = reader.bytes();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceTransaction message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceTransaction} BinanceTransaction
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTransaction.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceTransaction message.
                 * @function verify
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceTransaction.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.msgs != null && message.hasOwnProperty("msgs")) {
                        if (!Array.isArray(message.msgs))
                            return "msgs: array expected";
                        for (var i = 0; i < message.msgs.length; ++i)
                            if (!(message.msgs[i] && typeof message.msgs[i].length === "number" || $util.isString(message.msgs[i])))
                                return "msgs: buffer[] expected";
                    }
                    if (message.signatures != null && message.hasOwnProperty("signatures")) {
                        if (!Array.isArray(message.signatures))
                            return "signatures: array expected";
                        for (var i = 0; i < message.signatures.length; ++i)
                            if (!(message.signatures[i] && typeof message.signatures[i].length === "number" || $util.isString(message.signatures[i])))
                                return "signatures: buffer[] expected";
                    }
                    if (message.memo != null && message.hasOwnProperty("memo"))
                        if (!$util.isString(message.memo))
                            return "memo: string expected";
                    if (message.source != null && message.hasOwnProperty("source"))
                        if (!$util.isInteger(message.source) && !(message.source && $util.isInteger(message.source.low) && $util.isInteger(message.source.high)))
                            return "source: integer|Long expected";
                    if (message.data != null && message.hasOwnProperty("data"))
                        if (!(message.data && typeof message.data.length === "number" || $util.isString(message.data)))
                            return "data: buffer expected";
                    return null;
                };
    
                /**
                 * Creates a BinanceTransaction message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceTransaction} BinanceTransaction
                 */
                BinanceTransaction.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceTransaction)
                        return object;
                    var message = new $root.TW.proto.BinanceTransaction();
                    if (object.msgs) {
                        if (!Array.isArray(object.msgs))
                            throw TypeError(".TW.proto.BinanceTransaction.msgs: array expected");
                        message.msgs = [];
                        for (var i = 0; i < object.msgs.length; ++i)
                            if (typeof object.msgs[i] === "string")
                                $util.base64.decode(object.msgs[i], message.msgs[i] = $util.newBuffer($util.base64.length(object.msgs[i])), 0);
                            else if (object.msgs[i].length)
                                message.msgs[i] = object.msgs[i];
                    }
                    if (object.signatures) {
                        if (!Array.isArray(object.signatures))
                            throw TypeError(".TW.proto.BinanceTransaction.signatures: array expected");
                        message.signatures = [];
                        for (var i = 0; i < object.signatures.length; ++i)
                            if (typeof object.signatures[i] === "string")
                                $util.base64.decode(object.signatures[i], message.signatures[i] = $util.newBuffer($util.base64.length(object.signatures[i])), 0);
                            else if (object.signatures[i].length)
                                message.signatures[i] = object.signatures[i];
                    }
                    if (object.memo != null)
                        message.memo = String(object.memo);
                    if (object.source != null)
                        if ($util.Long)
                            (message.source = $util.Long.fromValue(object.source)).unsigned = false;
                        else if (typeof object.source === "string")
                            message.source = parseInt(object.source, 10);
                        else if (typeof object.source === "number")
                            message.source = object.source;
                        else if (typeof object.source === "object")
                            message.source = new $util.LongBits(object.source.low >>> 0, object.source.high >>> 0).toNumber();
                    if (object.data != null)
                        if (typeof object.data === "string")
                            $util.base64.decode(object.data, message.data = $util.newBuffer($util.base64.length(object.data)), 0);
                        else if (object.data.length)
                            message.data = object.data;
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceTransaction message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceTransaction
                 * @static
                 * @param {TW.proto.BinanceTransaction} message BinanceTransaction
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceTransaction.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.arrays || options.defaults) {
                        object.msgs = [];
                        object.signatures = [];
                    }
                    if (options.defaults) {
                        object.memo = "";
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.source = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.source = options.longs === String ? "0" : 0;
                        if (options.bytes === String)
                            object.data = "";
                        else {
                            object.data = [];
                            if (options.bytes !== Array)
                                object.data = $util.newBuffer(object.data);
                        }
                    }
                    if (message.msgs && message.msgs.length) {
                        object.msgs = [];
                        for (var j = 0; j < message.msgs.length; ++j)
                            object.msgs[j] = options.bytes === String ? $util.base64.encode(message.msgs[j], 0, message.msgs[j].length) : options.bytes === Array ? Array.prototype.slice.call(message.msgs[j]) : message.msgs[j];
                    }
                    if (message.signatures && message.signatures.length) {
                        object.signatures = [];
                        for (var j = 0; j < message.signatures.length; ++j)
                            object.signatures[j] = options.bytes === String ? $util.base64.encode(message.signatures[j], 0, message.signatures[j].length) : options.bytes === Array ? Array.prototype.slice.call(message.signatures[j]) : message.signatures[j];
                    }
                    if (message.memo != null && message.hasOwnProperty("memo"))
                        object.memo = message.memo;
                    if (message.source != null && message.hasOwnProperty("source"))
                        if (typeof message.source === "number")
                            object.source = options.longs === String ? String(message.source) : message.source;
                        else
                            object.source = options.longs === String ? $util.Long.prototype.toString.call(message.source) : options.longs === Number ? new $util.LongBits(message.source.low >>> 0, message.source.high >>> 0).toNumber() : message.source;
                    if (message.data != null && message.hasOwnProperty("data"))
                        object.data = options.bytes === String ? $util.base64.encode(message.data, 0, message.data.length) : options.bytes === Array ? Array.prototype.slice.call(message.data) : message.data;
                    return object;
                };
    
                /**
                 * Converts this BinanceTransaction to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceTransaction
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceTransaction.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BinanceTransaction;
            })();
    
            proto.BinanceSignature = (function() {
    
                /**
                 * Properties of a BinanceSignature.
                 * @memberof TW.proto
                 * @interface IBinanceSignature
                 * @property {Uint8Array|null} [pubKey] BinanceSignature pubKey
                 * @property {Uint8Array|null} [signature] BinanceSignature signature
                 * @property {Long|null} [accountNumber] BinanceSignature accountNumber
                 * @property {Long|null} [sequence] BinanceSignature sequence
                 */
    
                /**
                 * Constructs a new BinanceSignature.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceSignature.
                 * @implements IBinanceSignature
                 * @constructor
                 * @param {TW.proto.IBinanceSignature=} [properties] Properties to set
                 */
                function BinanceSignature(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceSignature pubKey.
                 * @member {Uint8Array} pubKey
                 * @memberof TW.proto.BinanceSignature
                 * @instance
                 */
                BinanceSignature.prototype.pubKey = $util.newBuffer([]);
    
                /**
                 * BinanceSignature signature.
                 * @member {Uint8Array} signature
                 * @memberof TW.proto.BinanceSignature
                 * @instance
                 */
                BinanceSignature.prototype.signature = $util.newBuffer([]);
    
                /**
                 * BinanceSignature accountNumber.
                 * @member {Long} accountNumber
                 * @memberof TW.proto.BinanceSignature
                 * @instance
                 */
                BinanceSignature.prototype.accountNumber = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceSignature sequence.
                 * @member {Long} sequence
                 * @memberof TW.proto.BinanceSignature
                 * @instance
                 */
                BinanceSignature.prototype.sequence = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * Creates a new BinanceSignature instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {TW.proto.IBinanceSignature=} [properties] Properties to set
                 * @returns {TW.proto.BinanceSignature} BinanceSignature instance
                 */
                BinanceSignature.create = function create(properties) {
                    return new BinanceSignature(properties);
                };
    
                /**
                 * Encodes the specified BinanceSignature message. Does not implicitly {@link TW.proto.BinanceSignature.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {TW.proto.IBinanceSignature} message BinanceSignature message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceSignature.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.pubKey != null && message.hasOwnProperty("pubKey"))
                        writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.pubKey);
                    if (message.signature != null && message.hasOwnProperty("signature"))
                        writer.uint32(/* id 2, wireType 2 =*/18).bytes(message.signature);
                    if (message.accountNumber != null && message.hasOwnProperty("accountNumber"))
                        writer.uint32(/* id 3, wireType 0 =*/24).int64(message.accountNumber);
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        writer.uint32(/* id 4, wireType 0 =*/32).int64(message.sequence);
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceSignature message, length delimited. Does not implicitly {@link TW.proto.BinanceSignature.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {TW.proto.IBinanceSignature} message BinanceSignature message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceSignature.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceSignature message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceSignature} BinanceSignature
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceSignature.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSignature();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.pubKey = reader.bytes();
                            break;
                        case 2:
                            message.signature = reader.bytes();
                            break;
                        case 3:
                            message.accountNumber = reader.int64();
                            break;
                        case 4:
                            message.sequence = reader.int64();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceSignature message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceSignature} BinanceSignature
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceSignature.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceSignature message.
                 * @function verify
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceSignature.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.pubKey != null && message.hasOwnProperty("pubKey"))
                        if (!(message.pubKey && typeof message.pubKey.length === "number" || $util.isString(message.pubKey)))
                            return "pubKey: buffer expected";
                    if (message.signature != null && message.hasOwnProperty("signature"))
                        if (!(message.signature && typeof message.signature.length === "number" || $util.isString(message.signature)))
                            return "signature: buffer expected";
                    if (message.accountNumber != null && message.hasOwnProperty("accountNumber"))
                        if (!$util.isInteger(message.accountNumber) && !(message.accountNumber && $util.isInteger(message.accountNumber.low) && $util.isInteger(message.accountNumber.high)))
                            return "accountNumber: integer|Long expected";
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        if (!$util.isInteger(message.sequence) && !(message.sequence && $util.isInteger(message.sequence.low) && $util.isInteger(message.sequence.high)))
                            return "sequence: integer|Long expected";
                    return null;
                };
    
                /**
                 * Creates a BinanceSignature message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceSignature} BinanceSignature
                 */
                BinanceSignature.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceSignature)
                        return object;
                    var message = new $root.TW.proto.BinanceSignature();
                    if (object.pubKey != null)
                        if (typeof object.pubKey === "string")
                            $util.base64.decode(object.pubKey, message.pubKey = $util.newBuffer($util.base64.length(object.pubKey)), 0);
                        else if (object.pubKey.length)
                            message.pubKey = object.pubKey;
                    if (object.signature != null)
                        if (typeof object.signature === "string")
                            $util.base64.decode(object.signature, message.signature = $util.newBuffer($util.base64.length(object.signature)), 0);
                        else if (object.signature.length)
                            message.signature = object.signature;
                    if (object.accountNumber != null)
                        if ($util.Long)
                            (message.accountNumber = $util.Long.fromValue(object.accountNumber)).unsigned = false;
                        else if (typeof object.accountNumber === "string")
                            message.accountNumber = parseInt(object.accountNumber, 10);
                        else if (typeof object.accountNumber === "number")
                            message.accountNumber = object.accountNumber;
                        else if (typeof object.accountNumber === "object")
                            message.accountNumber = new $util.LongBits(object.accountNumber.low >>> 0, object.accountNumber.high >>> 0).toNumber();
                    if (object.sequence != null)
                        if ($util.Long)
                            (message.sequence = $util.Long.fromValue(object.sequence)).unsigned = false;
                        else if (typeof object.sequence === "string")
                            message.sequence = parseInt(object.sequence, 10);
                        else if (typeof object.sequence === "number")
                            message.sequence = object.sequence;
                        else if (typeof object.sequence === "object")
                            message.sequence = new $util.LongBits(object.sequence.low >>> 0, object.sequence.high >>> 0).toNumber();
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceSignature message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceSignature
                 * @static
                 * @param {TW.proto.BinanceSignature} message BinanceSignature
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceSignature.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if (options.bytes === String)
                            object.pubKey = "";
                        else {
                            object.pubKey = [];
                            if (options.bytes !== Array)
                                object.pubKey = $util.newBuffer(object.pubKey);
                        }
                        if (options.bytes === String)
                            object.signature = "";
                        else {
                            object.signature = [];
                            if (options.bytes !== Array)
                                object.signature = $util.newBuffer(object.signature);
                        }
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.accountNumber = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.accountNumber = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.sequence = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.sequence = options.longs === String ? "0" : 0;
                    }
                    if (message.pubKey != null && message.hasOwnProperty("pubKey"))
                        object.pubKey = options.bytes === String ? $util.base64.encode(message.pubKey, 0, message.pubKey.length) : options.bytes === Array ? Array.prototype.slice.call(message.pubKey) : message.pubKey;
                    if (message.signature != null && message.hasOwnProperty("signature"))
                        object.signature = options.bytes === String ? $util.base64.encode(message.signature, 0, message.signature.length) : options.bytes === Array ? Array.prototype.slice.call(message.signature) : message.signature;
                    if (message.accountNumber != null && message.hasOwnProperty("accountNumber"))
                        if (typeof message.accountNumber === "number")
                            object.accountNumber = options.longs === String ? String(message.accountNumber) : message.accountNumber;
                        else
                            object.accountNumber = options.longs === String ? $util.Long.prototype.toString.call(message.accountNumber) : options.longs === Number ? new $util.LongBits(message.accountNumber.low >>> 0, message.accountNumber.high >>> 0).toNumber() : message.accountNumber;
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        if (typeof message.sequence === "number")
                            object.sequence = options.longs === String ? String(message.sequence) : message.sequence;
                        else
                            object.sequence = options.longs === String ? $util.Long.prototype.toString.call(message.sequence) : options.longs === Number ? new $util.LongBits(message.sequence.low >>> 0, message.sequence.high >>> 0).toNumber() : message.sequence;
                    return object;
                };
    
                /**
                 * Converts this BinanceSignature to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceSignature
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceSignature.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                BinanceSignature.PubKey = (function() {
    
                    /**
                     * Properties of a PubKey.
                     * @memberof TW.proto.BinanceSignature
                     * @interface IPubKey
                     */
    
                    /**
                     * Constructs a new PubKey.
                     * @memberof TW.proto.BinanceSignature
                     * @classdesc Represents a PubKey.
                     * @implements IPubKey
                     * @constructor
                     * @param {TW.proto.BinanceSignature.IPubKey=} [properties] Properties to set
                     */
                    function PubKey(properties) {
                        if (properties)
                            for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                                if (properties[keys[i]] != null)
                                    this[keys[i]] = properties[keys[i]];
                    }
    
                    /**
                     * Creates a new PubKey instance using the specified properties.
                     * @function create
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {TW.proto.BinanceSignature.IPubKey=} [properties] Properties to set
                     * @returns {TW.proto.BinanceSignature.PubKey} PubKey instance
                     */
                    PubKey.create = function create(properties) {
                        return new PubKey(properties);
                    };
    
                    /**
                     * Encodes the specified PubKey message. Does not implicitly {@link TW.proto.BinanceSignature.PubKey.verify|verify} messages.
                     * @function encode
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {TW.proto.BinanceSignature.IPubKey} message PubKey message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    PubKey.encode = function encode(message, writer) {
                        if (!writer)
                            writer = $Writer.create();
                        return writer;
                    };
    
                    /**
                     * Encodes the specified PubKey message, length delimited. Does not implicitly {@link TW.proto.BinanceSignature.PubKey.verify|verify} messages.
                     * @function encodeDelimited
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {TW.proto.BinanceSignature.IPubKey} message PubKey message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    PubKey.encodeDelimited = function encodeDelimited(message, writer) {
                        return this.encode(message, writer).ldelim();
                    };
    
                    /**
                     * Decodes a PubKey message from the specified reader or buffer.
                     * @function decode
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @param {number} [length] Message length if known beforehand
                     * @returns {TW.proto.BinanceSignature.PubKey} PubKey
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    PubKey.decode = function decode(reader, length) {
                        if (!(reader instanceof $Reader))
                            reader = $Reader.create(reader);
                        var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSignature.PubKey();
                        while (reader.pos < end) {
                            var tag = reader.uint32();
                            switch (tag >>> 3) {
                            default:
                                reader.skipType(tag & 7);
                                break;
                            }
                        }
                        return message;
                    };
    
                    /**
                     * Decodes a PubKey message from the specified reader or buffer, length delimited.
                     * @function decodeDelimited
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @returns {TW.proto.BinanceSignature.PubKey} PubKey
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    PubKey.decodeDelimited = function decodeDelimited(reader) {
                        if (!(reader instanceof $Reader))
                            reader = new $Reader(reader);
                        return this.decode(reader, reader.uint32());
                    };
    
                    /**
                     * Verifies a PubKey message.
                     * @function verify
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {Object.<string,*>} message Plain object to verify
                     * @returns {string|null} `null` if valid, otherwise the reason why it is not
                     */
                    PubKey.verify = function verify(message) {
                        if (typeof message !== "object" || message === null)
                            return "object expected";
                        return null;
                    };
    
                    /**
                     * Creates a PubKey message from a plain object. Also converts values to their respective internal types.
                     * @function fromObject
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {Object.<string,*>} object Plain object
                     * @returns {TW.proto.BinanceSignature.PubKey} PubKey
                     */
                    PubKey.fromObject = function fromObject(object) {
                        if (object instanceof $root.TW.proto.BinanceSignature.PubKey)
                            return object;
                        return new $root.TW.proto.BinanceSignature.PubKey();
                    };
    
                    /**
                     * Creates a plain object from a PubKey message. Also converts values to other types if specified.
                     * @function toObject
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @static
                     * @param {TW.proto.BinanceSignature.PubKey} message PubKey
                     * @param {$protobuf.IConversionOptions} [options] Conversion options
                     * @returns {Object.<string,*>} Plain object
                     */
                    PubKey.toObject = function toObject() {
                        return {};
                    };
    
                    /**
                     * Converts this PubKey to JSON.
                     * @function toJSON
                     * @memberof TW.proto.BinanceSignature.PubKey
                     * @instance
                     * @returns {Object.<string,*>} JSON object
                     */
                    PubKey.prototype.toJSON = function toJSON() {
                        return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                    };
    
                    return PubKey;
                })();
    
                return BinanceSignature;
            })();
    
            proto.BinanceTradeOrder = (function() {
    
                /**
                 * Properties of a BinanceTradeOrder.
                 * @memberof TW.proto
                 * @interface IBinanceTradeOrder
                 * @property {Uint8Array|null} [sender] BinanceTradeOrder sender
                 * @property {string|null} [id] BinanceTradeOrder id
                 * @property {string|null} [symbol] BinanceTradeOrder symbol
                 * @property {Long|null} [ordertype] BinanceTradeOrder ordertype
                 * @property {Long|null} [side] BinanceTradeOrder side
                 * @property {Long|null} [price] BinanceTradeOrder price
                 * @property {Long|null} [quantity] BinanceTradeOrder quantity
                 * @property {Long|null} [timeinforce] BinanceTradeOrder timeinforce
                 */
    
                /**
                 * Constructs a new BinanceTradeOrder.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceTradeOrder.
                 * @implements IBinanceTradeOrder
                 * @constructor
                 * @param {TW.proto.IBinanceTradeOrder=} [properties] Properties to set
                 */
                function BinanceTradeOrder(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceTradeOrder sender.
                 * @member {Uint8Array} sender
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.sender = $util.newBuffer([]);
    
                /**
                 * BinanceTradeOrder id.
                 * @member {string} id
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.id = "";
    
                /**
                 * BinanceTradeOrder symbol.
                 * @member {string} symbol
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.symbol = "";
    
                /**
                 * BinanceTradeOrder ordertype.
                 * @member {Long} ordertype
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.ordertype = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceTradeOrder side.
                 * @member {Long} side
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.side = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceTradeOrder price.
                 * @member {Long} price
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.price = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceTradeOrder quantity.
                 * @member {Long} quantity
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.quantity = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceTradeOrder timeinforce.
                 * @member {Long} timeinforce
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 */
                BinanceTradeOrder.prototype.timeinforce = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * Creates a new BinanceTradeOrder instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {TW.proto.IBinanceTradeOrder=} [properties] Properties to set
                 * @returns {TW.proto.BinanceTradeOrder} BinanceTradeOrder instance
                 */
                BinanceTradeOrder.create = function create(properties) {
                    return new BinanceTradeOrder(properties);
                };
    
                /**
                 * Encodes the specified BinanceTradeOrder message. Does not implicitly {@link TW.proto.BinanceTradeOrder.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {TW.proto.IBinanceTradeOrder} message BinanceTradeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTradeOrder.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.sender != null && message.hasOwnProperty("sender"))
                        writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.sender);
                    if (message.id != null && message.hasOwnProperty("id"))
                        writer.uint32(/* id 2, wireType 2 =*/18).string(message.id);
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        writer.uint32(/* id 3, wireType 2 =*/26).string(message.symbol);
                    if (message.ordertype != null && message.hasOwnProperty("ordertype"))
                        writer.uint32(/* id 4, wireType 0 =*/32).int64(message.ordertype);
                    if (message.side != null && message.hasOwnProperty("side"))
                        writer.uint32(/* id 5, wireType 0 =*/40).int64(message.side);
                    if (message.price != null && message.hasOwnProperty("price"))
                        writer.uint32(/* id 6, wireType 0 =*/48).int64(message.price);
                    if (message.quantity != null && message.hasOwnProperty("quantity"))
                        writer.uint32(/* id 7, wireType 0 =*/56).int64(message.quantity);
                    if (message.timeinforce != null && message.hasOwnProperty("timeinforce"))
                        writer.uint32(/* id 8, wireType 0 =*/64).int64(message.timeinforce);
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceTradeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceTradeOrder.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {TW.proto.IBinanceTradeOrder} message BinanceTradeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTradeOrder.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceTradeOrder message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceTradeOrder} BinanceTradeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTradeOrder.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceTradeOrder();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.sender = reader.bytes();
                            break;
                        case 2:
                            message.id = reader.string();
                            break;
                        case 3:
                            message.symbol = reader.string();
                            break;
                        case 4:
                            message.ordertype = reader.int64();
                            break;
                        case 5:
                            message.side = reader.int64();
                            break;
                        case 6:
                            message.price = reader.int64();
                            break;
                        case 7:
                            message.quantity = reader.int64();
                            break;
                        case 8:
                            message.timeinforce = reader.int64();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceTradeOrder message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceTradeOrder} BinanceTradeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTradeOrder.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceTradeOrder message.
                 * @function verify
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceTradeOrder.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.sender != null && message.hasOwnProperty("sender"))
                        if (!(message.sender && typeof message.sender.length === "number" || $util.isString(message.sender)))
                            return "sender: buffer expected";
                    if (message.id != null && message.hasOwnProperty("id"))
                        if (!$util.isString(message.id))
                            return "id: string expected";
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        if (!$util.isString(message.symbol))
                            return "symbol: string expected";
                    if (message.ordertype != null && message.hasOwnProperty("ordertype"))
                        if (!$util.isInteger(message.ordertype) && !(message.ordertype && $util.isInteger(message.ordertype.low) && $util.isInteger(message.ordertype.high)))
                            return "ordertype: integer|Long expected";
                    if (message.side != null && message.hasOwnProperty("side"))
                        if (!$util.isInteger(message.side) && !(message.side && $util.isInteger(message.side.low) && $util.isInteger(message.side.high)))
                            return "side: integer|Long expected";
                    if (message.price != null && message.hasOwnProperty("price"))
                        if (!$util.isInteger(message.price) && !(message.price && $util.isInteger(message.price.low) && $util.isInteger(message.price.high)))
                            return "price: integer|Long expected";
                    if (message.quantity != null && message.hasOwnProperty("quantity"))
                        if (!$util.isInteger(message.quantity) && !(message.quantity && $util.isInteger(message.quantity.low) && $util.isInteger(message.quantity.high)))
                            return "quantity: integer|Long expected";
                    if (message.timeinforce != null && message.hasOwnProperty("timeinforce"))
                        if (!$util.isInteger(message.timeinforce) && !(message.timeinforce && $util.isInteger(message.timeinforce.low) && $util.isInteger(message.timeinforce.high)))
                            return "timeinforce: integer|Long expected";
                    return null;
                };
    
                /**
                 * Creates a BinanceTradeOrder message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceTradeOrder} BinanceTradeOrder
                 */
                BinanceTradeOrder.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceTradeOrder)
                        return object;
                    var message = new $root.TW.proto.BinanceTradeOrder();
                    if (object.sender != null)
                        if (typeof object.sender === "string")
                            $util.base64.decode(object.sender, message.sender = $util.newBuffer($util.base64.length(object.sender)), 0);
                        else if (object.sender.length)
                            message.sender = object.sender;
                    if (object.id != null)
                        message.id = String(object.id);
                    if (object.symbol != null)
                        message.symbol = String(object.symbol);
                    if (object.ordertype != null)
                        if ($util.Long)
                            (message.ordertype = $util.Long.fromValue(object.ordertype)).unsigned = false;
                        else if (typeof object.ordertype === "string")
                            message.ordertype = parseInt(object.ordertype, 10);
                        else if (typeof object.ordertype === "number")
                            message.ordertype = object.ordertype;
                        else if (typeof object.ordertype === "object")
                            message.ordertype = new $util.LongBits(object.ordertype.low >>> 0, object.ordertype.high >>> 0).toNumber();
                    if (object.side != null)
                        if ($util.Long)
                            (message.side = $util.Long.fromValue(object.side)).unsigned = false;
                        else if (typeof object.side === "string")
                            message.side = parseInt(object.side, 10);
                        else if (typeof object.side === "number")
                            message.side = object.side;
                        else if (typeof object.side === "object")
                            message.side = new $util.LongBits(object.side.low >>> 0, object.side.high >>> 0).toNumber();
                    if (object.price != null)
                        if ($util.Long)
                            (message.price = $util.Long.fromValue(object.price)).unsigned = false;
                        else if (typeof object.price === "string")
                            message.price = parseInt(object.price, 10);
                        else if (typeof object.price === "number")
                            message.price = object.price;
                        else if (typeof object.price === "object")
                            message.price = new $util.LongBits(object.price.low >>> 0, object.price.high >>> 0).toNumber();
                    if (object.quantity != null)
                        if ($util.Long)
                            (message.quantity = $util.Long.fromValue(object.quantity)).unsigned = false;
                        else if (typeof object.quantity === "string")
                            message.quantity = parseInt(object.quantity, 10);
                        else if (typeof object.quantity === "number")
                            message.quantity = object.quantity;
                        else if (typeof object.quantity === "object")
                            message.quantity = new $util.LongBits(object.quantity.low >>> 0, object.quantity.high >>> 0).toNumber();
                    if (object.timeinforce != null)
                        if ($util.Long)
                            (message.timeinforce = $util.Long.fromValue(object.timeinforce)).unsigned = false;
                        else if (typeof object.timeinforce === "string")
                            message.timeinforce = parseInt(object.timeinforce, 10);
                        else if (typeof object.timeinforce === "number")
                            message.timeinforce = object.timeinforce;
                        else if (typeof object.timeinforce === "object")
                            message.timeinforce = new $util.LongBits(object.timeinforce.low >>> 0, object.timeinforce.high >>> 0).toNumber();
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceTradeOrder message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceTradeOrder
                 * @static
                 * @param {TW.proto.BinanceTradeOrder} message BinanceTradeOrder
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceTradeOrder.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if (options.bytes === String)
                            object.sender = "";
                        else {
                            object.sender = [];
                            if (options.bytes !== Array)
                                object.sender = $util.newBuffer(object.sender);
                        }
                        object.id = "";
                        object.symbol = "";
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.ordertype = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.ordertype = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.side = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.side = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.price = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.price = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.quantity = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.quantity = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.timeinforce = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.timeinforce = options.longs === String ? "0" : 0;
                    }
                    if (message.sender != null && message.hasOwnProperty("sender"))
                        object.sender = options.bytes === String ? $util.base64.encode(message.sender, 0, message.sender.length) : options.bytes === Array ? Array.prototype.slice.call(message.sender) : message.sender;
                    if (message.id != null && message.hasOwnProperty("id"))
                        object.id = message.id;
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        object.symbol = message.symbol;
                    if (message.ordertype != null && message.hasOwnProperty("ordertype"))
                        if (typeof message.ordertype === "number")
                            object.ordertype = options.longs === String ? String(message.ordertype) : message.ordertype;
                        else
                            object.ordertype = options.longs === String ? $util.Long.prototype.toString.call(message.ordertype) : options.longs === Number ? new $util.LongBits(message.ordertype.low >>> 0, message.ordertype.high >>> 0).toNumber() : message.ordertype;
                    if (message.side != null && message.hasOwnProperty("side"))
                        if (typeof message.side === "number")
                            object.side = options.longs === String ? String(message.side) : message.side;
                        else
                            object.side = options.longs === String ? $util.Long.prototype.toString.call(message.side) : options.longs === Number ? new $util.LongBits(message.side.low >>> 0, message.side.high >>> 0).toNumber() : message.side;
                    if (message.price != null && message.hasOwnProperty("price"))
                        if (typeof message.price === "number")
                            object.price = options.longs === String ? String(message.price) : message.price;
                        else
                            object.price = options.longs === String ? $util.Long.prototype.toString.call(message.price) : options.longs === Number ? new $util.LongBits(message.price.low >>> 0, message.price.high >>> 0).toNumber() : message.price;
                    if (message.quantity != null && message.hasOwnProperty("quantity"))
                        if (typeof message.quantity === "number")
                            object.quantity = options.longs === String ? String(message.quantity) : message.quantity;
                        else
                            object.quantity = options.longs === String ? $util.Long.prototype.toString.call(message.quantity) : options.longs === Number ? new $util.LongBits(message.quantity.low >>> 0, message.quantity.high >>> 0).toNumber() : message.quantity;
                    if (message.timeinforce != null && message.hasOwnProperty("timeinforce"))
                        if (typeof message.timeinforce === "number")
                            object.timeinforce = options.longs === String ? String(message.timeinforce) : message.timeinforce;
                        else
                            object.timeinforce = options.longs === String ? $util.Long.prototype.toString.call(message.timeinforce) : options.longs === Number ? new $util.LongBits(message.timeinforce.low >>> 0, message.timeinforce.high >>> 0).toNumber() : message.timeinforce;
                    return object;
                };
    
                /**
                 * Converts this BinanceTradeOrder to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceTradeOrder
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceTradeOrder.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BinanceTradeOrder;
            })();
    
            proto.BinanceCancelTradeOrder = (function() {
    
                /**
                 * Properties of a BinanceCancelTradeOrder.
                 * @memberof TW.proto
                 * @interface IBinanceCancelTradeOrder
                 * @property {Uint8Array|null} [sender] BinanceCancelTradeOrder sender
                 * @property {string|null} [symbol] BinanceCancelTradeOrder symbol
                 * @property {string|null} [refid] BinanceCancelTradeOrder refid
                 */
    
                /**
                 * Constructs a new BinanceCancelTradeOrder.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceCancelTradeOrder.
                 * @implements IBinanceCancelTradeOrder
                 * @constructor
                 * @param {TW.proto.IBinanceCancelTradeOrder=} [properties] Properties to set
                 */
                function BinanceCancelTradeOrder(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceCancelTradeOrder sender.
                 * @member {Uint8Array} sender
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @instance
                 */
                BinanceCancelTradeOrder.prototype.sender = $util.newBuffer([]);
    
                /**
                 * BinanceCancelTradeOrder symbol.
                 * @member {string} symbol
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @instance
                 */
                BinanceCancelTradeOrder.prototype.symbol = "";
    
                /**
                 * BinanceCancelTradeOrder refid.
                 * @member {string} refid
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @instance
                 */
                BinanceCancelTradeOrder.prototype.refid = "";
    
                /**
                 * Creates a new BinanceCancelTradeOrder instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {TW.proto.IBinanceCancelTradeOrder=} [properties] Properties to set
                 * @returns {TW.proto.BinanceCancelTradeOrder} BinanceCancelTradeOrder instance
                 */
                BinanceCancelTradeOrder.create = function create(properties) {
                    return new BinanceCancelTradeOrder(properties);
                };
    
                /**
                 * Encodes the specified BinanceCancelTradeOrder message. Does not implicitly {@link TW.proto.BinanceCancelTradeOrder.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {TW.proto.IBinanceCancelTradeOrder} message BinanceCancelTradeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceCancelTradeOrder.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.sender != null && message.hasOwnProperty("sender"))
                        writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.sender);
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        writer.uint32(/* id 2, wireType 2 =*/18).string(message.symbol);
                    if (message.refid != null && message.hasOwnProperty("refid"))
                        writer.uint32(/* id 4, wireType 2 =*/34).string(message.refid);
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceCancelTradeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceCancelTradeOrder.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {TW.proto.IBinanceCancelTradeOrder} message BinanceCancelTradeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceCancelTradeOrder.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceCancelTradeOrder message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceCancelTradeOrder} BinanceCancelTradeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceCancelTradeOrder.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceCancelTradeOrder();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.sender = reader.bytes();
                            break;
                        case 2:
                            message.symbol = reader.string();
                            break;
                        case 4:
                            message.refid = reader.string();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceCancelTradeOrder message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceCancelTradeOrder} BinanceCancelTradeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceCancelTradeOrder.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceCancelTradeOrder message.
                 * @function verify
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceCancelTradeOrder.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.sender != null && message.hasOwnProperty("sender"))
                        if (!(message.sender && typeof message.sender.length === "number" || $util.isString(message.sender)))
                            return "sender: buffer expected";
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        if (!$util.isString(message.symbol))
                            return "symbol: string expected";
                    if (message.refid != null && message.hasOwnProperty("refid"))
                        if (!$util.isString(message.refid))
                            return "refid: string expected";
                    return null;
                };
    
                /**
                 * Creates a BinanceCancelTradeOrder message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceCancelTradeOrder} BinanceCancelTradeOrder
                 */
                BinanceCancelTradeOrder.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceCancelTradeOrder)
                        return object;
                    var message = new $root.TW.proto.BinanceCancelTradeOrder();
                    if (object.sender != null)
                        if (typeof object.sender === "string")
                            $util.base64.decode(object.sender, message.sender = $util.newBuffer($util.base64.length(object.sender)), 0);
                        else if (object.sender.length)
                            message.sender = object.sender;
                    if (object.symbol != null)
                        message.symbol = String(object.symbol);
                    if (object.refid != null)
                        message.refid = String(object.refid);
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceCancelTradeOrder message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @static
                 * @param {TW.proto.BinanceCancelTradeOrder} message BinanceCancelTradeOrder
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceCancelTradeOrder.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if (options.bytes === String)
                            object.sender = "";
                        else {
                            object.sender = [];
                            if (options.bytes !== Array)
                                object.sender = $util.newBuffer(object.sender);
                        }
                        object.symbol = "";
                        object.refid = "";
                    }
                    if (message.sender != null && message.hasOwnProperty("sender"))
                        object.sender = options.bytes === String ? $util.base64.encode(message.sender, 0, message.sender.length) : options.bytes === Array ? Array.prototype.slice.call(message.sender) : message.sender;
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        object.symbol = message.symbol;
                    if (message.refid != null && message.hasOwnProperty("refid"))
                        object.refid = message.refid;
                    return object;
                };
    
                /**
                 * Converts this BinanceCancelTradeOrder to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceCancelTradeOrder
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceCancelTradeOrder.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BinanceCancelTradeOrder;
            })();
    
            proto.BinanceSendOrder = (function() {
    
                /**
                 * Properties of a BinanceSendOrder.
                 * @memberof TW.proto
                 * @interface IBinanceSendOrder
                 * @property {Array.<TW.proto.BinanceSendOrder.IInput>|null} [inputs] BinanceSendOrder inputs
                 * @property {Array.<TW.proto.BinanceSendOrder.IOutput>|null} [outputs] BinanceSendOrder outputs
                 */
    
                /**
                 * Constructs a new BinanceSendOrder.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceSendOrder.
                 * @implements IBinanceSendOrder
                 * @constructor
                 * @param {TW.proto.IBinanceSendOrder=} [properties] Properties to set
                 */
                function BinanceSendOrder(properties) {
                    this.inputs = [];
                    this.outputs = [];
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceSendOrder inputs.
                 * @member {Array.<TW.proto.BinanceSendOrder.IInput>} inputs
                 * @memberof TW.proto.BinanceSendOrder
                 * @instance
                 */
                BinanceSendOrder.prototype.inputs = $util.emptyArray;
    
                /**
                 * BinanceSendOrder outputs.
                 * @member {Array.<TW.proto.BinanceSendOrder.IOutput>} outputs
                 * @memberof TW.proto.BinanceSendOrder
                 * @instance
                 */
                BinanceSendOrder.prototype.outputs = $util.emptyArray;
    
                /**
                 * Creates a new BinanceSendOrder instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {TW.proto.IBinanceSendOrder=} [properties] Properties to set
                 * @returns {TW.proto.BinanceSendOrder} BinanceSendOrder instance
                 */
                BinanceSendOrder.create = function create(properties) {
                    return new BinanceSendOrder(properties);
                };
    
                /**
                 * Encodes the specified BinanceSendOrder message. Does not implicitly {@link TW.proto.BinanceSendOrder.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {TW.proto.IBinanceSendOrder} message BinanceSendOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceSendOrder.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.inputs != null && message.inputs.length)
                        for (var i = 0; i < message.inputs.length; ++i)
                            $root.TW.proto.BinanceSendOrder.Input.encode(message.inputs[i], writer.uint32(/* id 1, wireType 2 =*/10).fork()).ldelim();
                    if (message.outputs != null && message.outputs.length)
                        for (var i = 0; i < message.outputs.length; ++i)
                            $root.TW.proto.BinanceSendOrder.Output.encode(message.outputs[i], writer.uint32(/* id 2, wireType 2 =*/18).fork()).ldelim();
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceSendOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {TW.proto.IBinanceSendOrder} message BinanceSendOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceSendOrder.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceSendOrder message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceSendOrder} BinanceSendOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceSendOrder.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSendOrder();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            if (!(message.inputs && message.inputs.length))
                                message.inputs = [];
                            message.inputs.push($root.TW.proto.BinanceSendOrder.Input.decode(reader, reader.uint32()));
                            break;
                        case 2:
                            if (!(message.outputs && message.outputs.length))
                                message.outputs = [];
                            message.outputs.push($root.TW.proto.BinanceSendOrder.Output.decode(reader, reader.uint32()));
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceSendOrder message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceSendOrder} BinanceSendOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceSendOrder.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceSendOrder message.
                 * @function verify
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceSendOrder.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.inputs != null && message.hasOwnProperty("inputs")) {
                        if (!Array.isArray(message.inputs))
                            return "inputs: array expected";
                        for (var i = 0; i < message.inputs.length; ++i) {
                            var error = $root.TW.proto.BinanceSendOrder.Input.verify(message.inputs[i]);
                            if (error)
                                return "inputs." + error;
                        }
                    }
                    if (message.outputs != null && message.hasOwnProperty("outputs")) {
                        if (!Array.isArray(message.outputs))
                            return "outputs: array expected";
                        for (var i = 0; i < message.outputs.length; ++i) {
                            var error = $root.TW.proto.BinanceSendOrder.Output.verify(message.outputs[i]);
                            if (error)
                                return "outputs." + error;
                        }
                    }
                    return null;
                };
    
                /**
                 * Creates a BinanceSendOrder message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceSendOrder} BinanceSendOrder
                 */
                BinanceSendOrder.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceSendOrder)
                        return object;
                    var message = new $root.TW.proto.BinanceSendOrder();
                    if (object.inputs) {
                        if (!Array.isArray(object.inputs))
                            throw TypeError(".TW.proto.BinanceSendOrder.inputs: array expected");
                        message.inputs = [];
                        for (var i = 0; i < object.inputs.length; ++i) {
                            if (typeof object.inputs[i] !== "object")
                                throw TypeError(".TW.proto.BinanceSendOrder.inputs: object expected");
                            message.inputs[i] = $root.TW.proto.BinanceSendOrder.Input.fromObject(object.inputs[i]);
                        }
                    }
                    if (object.outputs) {
                        if (!Array.isArray(object.outputs))
                            throw TypeError(".TW.proto.BinanceSendOrder.outputs: array expected");
                        message.outputs = [];
                        for (var i = 0; i < object.outputs.length; ++i) {
                            if (typeof object.outputs[i] !== "object")
                                throw TypeError(".TW.proto.BinanceSendOrder.outputs: object expected");
                            message.outputs[i] = $root.TW.proto.BinanceSendOrder.Output.fromObject(object.outputs[i]);
                        }
                    }
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceSendOrder message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceSendOrder
                 * @static
                 * @param {TW.proto.BinanceSendOrder} message BinanceSendOrder
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceSendOrder.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.arrays || options.defaults) {
                        object.inputs = [];
                        object.outputs = [];
                    }
                    if (message.inputs && message.inputs.length) {
                        object.inputs = [];
                        for (var j = 0; j < message.inputs.length; ++j)
                            object.inputs[j] = $root.TW.proto.BinanceSendOrder.Input.toObject(message.inputs[j], options);
                    }
                    if (message.outputs && message.outputs.length) {
                        object.outputs = [];
                        for (var j = 0; j < message.outputs.length; ++j)
                            object.outputs[j] = $root.TW.proto.BinanceSendOrder.Output.toObject(message.outputs[j], options);
                    }
                    return object;
                };
    
                /**
                 * Converts this BinanceSendOrder to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceSendOrder
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceSendOrder.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                BinanceSendOrder.Token = (function() {
    
                    /**
                     * Properties of a Token.
                     * @memberof TW.proto.BinanceSendOrder
                     * @interface IToken
                     * @property {string|null} [denom] Token denom
                     * @property {Long|null} [amount] Token amount
                     */
    
                    /**
                     * Constructs a new Token.
                     * @memberof TW.proto.BinanceSendOrder
                     * @classdesc Represents a Token.
                     * @implements IToken
                     * @constructor
                     * @param {TW.proto.BinanceSendOrder.IToken=} [properties] Properties to set
                     */
                    function Token(properties) {
                        if (properties)
                            for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                                if (properties[keys[i]] != null)
                                    this[keys[i]] = properties[keys[i]];
                    }
    
                    /**
                     * Token denom.
                     * @member {string} denom
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @instance
                     */
                    Token.prototype.denom = "";
    
                    /**
                     * Token amount.
                     * @member {Long} amount
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @instance
                     */
                    Token.prototype.amount = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                    /**
                     * Creates a new Token instance using the specified properties.
                     * @function create
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IToken=} [properties] Properties to set
                     * @returns {TW.proto.BinanceSendOrder.Token} Token instance
                     */
                    Token.create = function create(properties) {
                        return new Token(properties);
                    };
    
                    /**
                     * Encodes the specified Token message. Does not implicitly {@link TW.proto.BinanceSendOrder.Token.verify|verify} messages.
                     * @function encode
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IToken} message Token message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    Token.encode = function encode(message, writer) {
                        if (!writer)
                            writer = $Writer.create();
                        if (message.denom != null && message.hasOwnProperty("denom"))
                            writer.uint32(/* id 1, wireType 2 =*/10).string(message.denom);
                        if (message.amount != null && message.hasOwnProperty("amount"))
                            writer.uint32(/* id 2, wireType 0 =*/16).int64(message.amount);
                        return writer;
                    };
    
                    /**
                     * Encodes the specified Token message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.Token.verify|verify} messages.
                     * @function encodeDelimited
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IToken} message Token message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    Token.encodeDelimited = function encodeDelimited(message, writer) {
                        return this.encode(message, writer).ldelim();
                    };
    
                    /**
                     * Decodes a Token message from the specified reader or buffer.
                     * @function decode
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @param {number} [length] Message length if known beforehand
                     * @returns {TW.proto.BinanceSendOrder.Token} Token
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    Token.decode = function decode(reader, length) {
                        if (!(reader instanceof $Reader))
                            reader = $Reader.create(reader);
                        var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSendOrder.Token();
                        while (reader.pos < end) {
                            var tag = reader.uint32();
                            switch (tag >>> 3) {
                            case 1:
                                message.denom = reader.string();
                                break;
                            case 2:
                                message.amount = reader.int64();
                                break;
                            default:
                                reader.skipType(tag & 7);
                                break;
                            }
                        }
                        return message;
                    };
    
                    /**
                     * Decodes a Token message from the specified reader or buffer, length delimited.
                     * @function decodeDelimited
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @returns {TW.proto.BinanceSendOrder.Token} Token
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    Token.decodeDelimited = function decodeDelimited(reader) {
                        if (!(reader instanceof $Reader))
                            reader = new $Reader(reader);
                        return this.decode(reader, reader.uint32());
                    };
    
                    /**
                     * Verifies a Token message.
                     * @function verify
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {Object.<string,*>} message Plain object to verify
                     * @returns {string|null} `null` if valid, otherwise the reason why it is not
                     */
                    Token.verify = function verify(message) {
                        if (typeof message !== "object" || message === null)
                            return "object expected";
                        if (message.denom != null && message.hasOwnProperty("denom"))
                            if (!$util.isString(message.denom))
                                return "denom: string expected";
                        if (message.amount != null && message.hasOwnProperty("amount"))
                            if (!$util.isInteger(message.amount) && !(message.amount && $util.isInteger(message.amount.low) && $util.isInteger(message.amount.high)))
                                return "amount: integer|Long expected";
                        return null;
                    };
    
                    /**
                     * Creates a Token message from a plain object. Also converts values to their respective internal types.
                     * @function fromObject
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {Object.<string,*>} object Plain object
                     * @returns {TW.proto.BinanceSendOrder.Token} Token
                     */
                    Token.fromObject = function fromObject(object) {
                        if (object instanceof $root.TW.proto.BinanceSendOrder.Token)
                            return object;
                        var message = new $root.TW.proto.BinanceSendOrder.Token();
                        if (object.denom != null)
                            message.denom = String(object.denom);
                        if (object.amount != null)
                            if ($util.Long)
                                (message.amount = $util.Long.fromValue(object.amount)).unsigned = false;
                            else if (typeof object.amount === "string")
                                message.amount = parseInt(object.amount, 10);
                            else if (typeof object.amount === "number")
                                message.amount = object.amount;
                            else if (typeof object.amount === "object")
                                message.amount = new $util.LongBits(object.amount.low >>> 0, object.amount.high >>> 0).toNumber();
                        return message;
                    };
    
                    /**
                     * Creates a plain object from a Token message. Also converts values to other types if specified.
                     * @function toObject
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @static
                     * @param {TW.proto.BinanceSendOrder.Token} message Token
                     * @param {$protobuf.IConversionOptions} [options] Conversion options
                     * @returns {Object.<string,*>} Plain object
                     */
                    Token.toObject = function toObject(message, options) {
                        if (!options)
                            options = {};
                        var object = {};
                        if (options.defaults) {
                            object.denom = "";
                            if ($util.Long) {
                                var long = new $util.Long(0, 0, false);
                                object.amount = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                            } else
                                object.amount = options.longs === String ? "0" : 0;
                        }
                        if (message.denom != null && message.hasOwnProperty("denom"))
                            object.denom = message.denom;
                        if (message.amount != null && message.hasOwnProperty("amount"))
                            if (typeof message.amount === "number")
                                object.amount = options.longs === String ? String(message.amount) : message.amount;
                            else
                                object.amount = options.longs === String ? $util.Long.prototype.toString.call(message.amount) : options.longs === Number ? new $util.LongBits(message.amount.low >>> 0, message.amount.high >>> 0).toNumber() : message.amount;
                        return object;
                    };
    
                    /**
                     * Converts this Token to JSON.
                     * @function toJSON
                     * @memberof TW.proto.BinanceSendOrder.Token
                     * @instance
                     * @returns {Object.<string,*>} JSON object
                     */
                    Token.prototype.toJSON = function toJSON() {
                        return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                    };
    
                    return Token;
                })();
    
                BinanceSendOrder.Input = (function() {
    
                    /**
                     * Properties of an Input.
                     * @memberof TW.proto.BinanceSendOrder
                     * @interface IInput
                     * @property {Uint8Array|null} [address] Input address
                     * @property {Array.<TW.proto.BinanceSendOrder.IToken>|null} [coins] Input coins
                     */
    
                    /**
                     * Constructs a new Input.
                     * @memberof TW.proto.BinanceSendOrder
                     * @classdesc Represents an Input.
                     * @implements IInput
                     * @constructor
                     * @param {TW.proto.BinanceSendOrder.IInput=} [properties] Properties to set
                     */
                    function Input(properties) {
                        this.coins = [];
                        if (properties)
                            for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                                if (properties[keys[i]] != null)
                                    this[keys[i]] = properties[keys[i]];
                    }
    
                    /**
                     * Input address.
                     * @member {Uint8Array} address
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @instance
                     */
                    Input.prototype.address = $util.newBuffer([]);
    
                    /**
                     * Input coins.
                     * @member {Array.<TW.proto.BinanceSendOrder.IToken>} coins
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @instance
                     */
                    Input.prototype.coins = $util.emptyArray;
    
                    /**
                     * Creates a new Input instance using the specified properties.
                     * @function create
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IInput=} [properties] Properties to set
                     * @returns {TW.proto.BinanceSendOrder.Input} Input instance
                     */
                    Input.create = function create(properties) {
                        return new Input(properties);
                    };
    
                    /**
                     * Encodes the specified Input message. Does not implicitly {@link TW.proto.BinanceSendOrder.Input.verify|verify} messages.
                     * @function encode
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IInput} message Input message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    Input.encode = function encode(message, writer) {
                        if (!writer)
                            writer = $Writer.create();
                        if (message.address != null && message.hasOwnProperty("address"))
                            writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.address);
                        if (message.coins != null && message.coins.length)
                            for (var i = 0; i < message.coins.length; ++i)
                                $root.TW.proto.BinanceSendOrder.Token.encode(message.coins[i], writer.uint32(/* id 2, wireType 2 =*/18).fork()).ldelim();
                        return writer;
                    };
    
                    /**
                     * Encodes the specified Input message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.Input.verify|verify} messages.
                     * @function encodeDelimited
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IInput} message Input message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    Input.encodeDelimited = function encodeDelimited(message, writer) {
                        return this.encode(message, writer).ldelim();
                    };
    
                    /**
                     * Decodes an Input message from the specified reader or buffer.
                     * @function decode
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @param {number} [length] Message length if known beforehand
                     * @returns {TW.proto.BinanceSendOrder.Input} Input
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    Input.decode = function decode(reader, length) {
                        if (!(reader instanceof $Reader))
                            reader = $Reader.create(reader);
                        var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSendOrder.Input();
                        while (reader.pos < end) {
                            var tag = reader.uint32();
                            switch (tag >>> 3) {
                            case 1:
                                message.address = reader.bytes();
                                break;
                            case 2:
                                if (!(message.coins && message.coins.length))
                                    message.coins = [];
                                message.coins.push($root.TW.proto.BinanceSendOrder.Token.decode(reader, reader.uint32()));
                                break;
                            default:
                                reader.skipType(tag & 7);
                                break;
                            }
                        }
                        return message;
                    };
    
                    /**
                     * Decodes an Input message from the specified reader or buffer, length delimited.
                     * @function decodeDelimited
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @returns {TW.proto.BinanceSendOrder.Input} Input
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    Input.decodeDelimited = function decodeDelimited(reader) {
                        if (!(reader instanceof $Reader))
                            reader = new $Reader(reader);
                        return this.decode(reader, reader.uint32());
                    };
    
                    /**
                     * Verifies an Input message.
                     * @function verify
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {Object.<string,*>} message Plain object to verify
                     * @returns {string|null} `null` if valid, otherwise the reason why it is not
                     */
                    Input.verify = function verify(message) {
                        if (typeof message !== "object" || message === null)
                            return "object expected";
                        if (message.address != null && message.hasOwnProperty("address"))
                            if (!(message.address && typeof message.address.length === "number" || $util.isString(message.address)))
                                return "address: buffer expected";
                        if (message.coins != null && message.hasOwnProperty("coins")) {
                            if (!Array.isArray(message.coins))
                                return "coins: array expected";
                            for (var i = 0; i < message.coins.length; ++i) {
                                var error = $root.TW.proto.BinanceSendOrder.Token.verify(message.coins[i]);
                                if (error)
                                    return "coins." + error;
                            }
                        }
                        return null;
                    };
    
                    /**
                     * Creates an Input message from a plain object. Also converts values to their respective internal types.
                     * @function fromObject
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {Object.<string,*>} object Plain object
                     * @returns {TW.proto.BinanceSendOrder.Input} Input
                     */
                    Input.fromObject = function fromObject(object) {
                        if (object instanceof $root.TW.proto.BinanceSendOrder.Input)
                            return object;
                        var message = new $root.TW.proto.BinanceSendOrder.Input();
                        if (object.address != null)
                            if (typeof object.address === "string")
                                $util.base64.decode(object.address, message.address = $util.newBuffer($util.base64.length(object.address)), 0);
                            else if (object.address.length)
                                message.address = object.address;
                        if (object.coins) {
                            if (!Array.isArray(object.coins))
                                throw TypeError(".TW.proto.BinanceSendOrder.Input.coins: array expected");
                            message.coins = [];
                            for (var i = 0; i < object.coins.length; ++i) {
                                if (typeof object.coins[i] !== "object")
                                    throw TypeError(".TW.proto.BinanceSendOrder.Input.coins: object expected");
                                message.coins[i] = $root.TW.proto.BinanceSendOrder.Token.fromObject(object.coins[i]);
                            }
                        }
                        return message;
                    };
    
                    /**
                     * Creates a plain object from an Input message. Also converts values to other types if specified.
                     * @function toObject
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @static
                     * @param {TW.proto.BinanceSendOrder.Input} message Input
                     * @param {$protobuf.IConversionOptions} [options] Conversion options
                     * @returns {Object.<string,*>} Plain object
                     */
                    Input.toObject = function toObject(message, options) {
                        if (!options)
                            options = {};
                        var object = {};
                        if (options.arrays || options.defaults)
                            object.coins = [];
                        if (options.defaults)
                            if (options.bytes === String)
                                object.address = "";
                            else {
                                object.address = [];
                                if (options.bytes !== Array)
                                    object.address = $util.newBuffer(object.address);
                            }
                        if (message.address != null && message.hasOwnProperty("address"))
                            object.address = options.bytes === String ? $util.base64.encode(message.address, 0, message.address.length) : options.bytes === Array ? Array.prototype.slice.call(message.address) : message.address;
                        if (message.coins && message.coins.length) {
                            object.coins = [];
                            for (var j = 0; j < message.coins.length; ++j)
                                object.coins[j] = $root.TW.proto.BinanceSendOrder.Token.toObject(message.coins[j], options);
                        }
                        return object;
                    };
    
                    /**
                     * Converts this Input to JSON.
                     * @function toJSON
                     * @memberof TW.proto.BinanceSendOrder.Input
                     * @instance
                     * @returns {Object.<string,*>} JSON object
                     */
                    Input.prototype.toJSON = function toJSON() {
                        return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                    };
    
                    return Input;
                })();
    
                BinanceSendOrder.Output = (function() {
    
                    /**
                     * Properties of an Output.
                     * @memberof TW.proto.BinanceSendOrder
                     * @interface IOutput
                     * @property {Uint8Array|null} [address] Output address
                     * @property {Array.<TW.proto.BinanceSendOrder.IToken>|null} [coins] Output coins
                     */
    
                    /**
                     * Constructs a new Output.
                     * @memberof TW.proto.BinanceSendOrder
                     * @classdesc Represents an Output.
                     * @implements IOutput
                     * @constructor
                     * @param {TW.proto.BinanceSendOrder.IOutput=} [properties] Properties to set
                     */
                    function Output(properties) {
                        this.coins = [];
                        if (properties)
                            for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                                if (properties[keys[i]] != null)
                                    this[keys[i]] = properties[keys[i]];
                    }
    
                    /**
                     * Output address.
                     * @member {Uint8Array} address
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @instance
                     */
                    Output.prototype.address = $util.newBuffer([]);
    
                    /**
                     * Output coins.
                     * @member {Array.<TW.proto.BinanceSendOrder.IToken>} coins
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @instance
                     */
                    Output.prototype.coins = $util.emptyArray;
    
                    /**
                     * Creates a new Output instance using the specified properties.
                     * @function create
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IOutput=} [properties] Properties to set
                     * @returns {TW.proto.BinanceSendOrder.Output} Output instance
                     */
                    Output.create = function create(properties) {
                        return new Output(properties);
                    };
    
                    /**
                     * Encodes the specified Output message. Does not implicitly {@link TW.proto.BinanceSendOrder.Output.verify|verify} messages.
                     * @function encode
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IOutput} message Output message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    Output.encode = function encode(message, writer) {
                        if (!writer)
                            writer = $Writer.create();
                        if (message.address != null && message.hasOwnProperty("address"))
                            writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.address);
                        if (message.coins != null && message.coins.length)
                            for (var i = 0; i < message.coins.length; ++i)
                                $root.TW.proto.BinanceSendOrder.Token.encode(message.coins[i], writer.uint32(/* id 2, wireType 2 =*/18).fork()).ldelim();
                        return writer;
                    };
    
                    /**
                     * Encodes the specified Output message, length delimited. Does not implicitly {@link TW.proto.BinanceSendOrder.Output.verify|verify} messages.
                     * @function encodeDelimited
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {TW.proto.BinanceSendOrder.IOutput} message Output message or plain object to encode
                     * @param {$protobuf.Writer} [writer] Writer to encode to
                     * @returns {$protobuf.Writer} Writer
                     */
                    Output.encodeDelimited = function encodeDelimited(message, writer) {
                        return this.encode(message, writer).ldelim();
                    };
    
                    /**
                     * Decodes an Output message from the specified reader or buffer.
                     * @function decode
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @param {number} [length] Message length if known beforehand
                     * @returns {TW.proto.BinanceSendOrder.Output} Output
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    Output.decode = function decode(reader, length) {
                        if (!(reader instanceof $Reader))
                            reader = $Reader.create(reader);
                        var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSendOrder.Output();
                        while (reader.pos < end) {
                            var tag = reader.uint32();
                            switch (tag >>> 3) {
                            case 1:
                                message.address = reader.bytes();
                                break;
                            case 2:
                                if (!(message.coins && message.coins.length))
                                    message.coins = [];
                                message.coins.push($root.TW.proto.BinanceSendOrder.Token.decode(reader, reader.uint32()));
                                break;
                            default:
                                reader.skipType(tag & 7);
                                break;
                            }
                        }
                        return message;
                    };
    
                    /**
                     * Decodes an Output message from the specified reader or buffer, length delimited.
                     * @function decodeDelimited
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                     * @returns {TW.proto.BinanceSendOrder.Output} Output
                     * @throws {Error} If the payload is not a reader or valid buffer
                     * @throws {$protobuf.util.ProtocolError} If required fields are missing
                     */
                    Output.decodeDelimited = function decodeDelimited(reader) {
                        if (!(reader instanceof $Reader))
                            reader = new $Reader(reader);
                        return this.decode(reader, reader.uint32());
                    };
    
                    /**
                     * Verifies an Output message.
                     * @function verify
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {Object.<string,*>} message Plain object to verify
                     * @returns {string|null} `null` if valid, otherwise the reason why it is not
                     */
                    Output.verify = function verify(message) {
                        if (typeof message !== "object" || message === null)
                            return "object expected";
                        if (message.address != null && message.hasOwnProperty("address"))
                            if (!(message.address && typeof message.address.length === "number" || $util.isString(message.address)))
                                return "address: buffer expected";
                        if (message.coins != null && message.hasOwnProperty("coins")) {
                            if (!Array.isArray(message.coins))
                                return "coins: array expected";
                            for (var i = 0; i < message.coins.length; ++i) {
                                var error = $root.TW.proto.BinanceSendOrder.Token.verify(message.coins[i]);
                                if (error)
                                    return "coins." + error;
                            }
                        }
                        return null;
                    };
    
                    /**
                     * Creates an Output message from a plain object. Also converts values to their respective internal types.
                     * @function fromObject
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {Object.<string,*>} object Plain object
                     * @returns {TW.proto.BinanceSendOrder.Output} Output
                     */
                    Output.fromObject = function fromObject(object) {
                        if (object instanceof $root.TW.proto.BinanceSendOrder.Output)
                            return object;
                        var message = new $root.TW.proto.BinanceSendOrder.Output();
                        if (object.address != null)
                            if (typeof object.address === "string")
                                $util.base64.decode(object.address, message.address = $util.newBuffer($util.base64.length(object.address)), 0);
                            else if (object.address.length)
                                message.address = object.address;
                        if (object.coins) {
                            if (!Array.isArray(object.coins))
                                throw TypeError(".TW.proto.BinanceSendOrder.Output.coins: array expected");
                            message.coins = [];
                            for (var i = 0; i < object.coins.length; ++i) {
                                if (typeof object.coins[i] !== "object")
                                    throw TypeError(".TW.proto.BinanceSendOrder.Output.coins: object expected");
                                message.coins[i] = $root.TW.proto.BinanceSendOrder.Token.fromObject(object.coins[i]);
                            }
                        }
                        return message;
                    };
    
                    /**
                     * Creates a plain object from an Output message. Also converts values to other types if specified.
                     * @function toObject
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @static
                     * @param {TW.proto.BinanceSendOrder.Output} message Output
                     * @param {$protobuf.IConversionOptions} [options] Conversion options
                     * @returns {Object.<string,*>} Plain object
                     */
                    Output.toObject = function toObject(message, options) {
                        if (!options)
                            options = {};
                        var object = {};
                        if (options.arrays || options.defaults)
                            object.coins = [];
                        if (options.defaults)
                            if (options.bytes === String)
                                object.address = "";
                            else {
                                object.address = [];
                                if (options.bytes !== Array)
                                    object.address = $util.newBuffer(object.address);
                            }
                        if (message.address != null && message.hasOwnProperty("address"))
                            object.address = options.bytes === String ? $util.base64.encode(message.address, 0, message.address.length) : options.bytes === Array ? Array.prototype.slice.call(message.address) : message.address;
                        if (message.coins && message.coins.length) {
                            object.coins = [];
                            for (var j = 0; j < message.coins.length; ++j)
                                object.coins[j] = $root.TW.proto.BinanceSendOrder.Token.toObject(message.coins[j], options);
                        }
                        return object;
                    };
    
                    /**
                     * Converts this Output to JSON.
                     * @function toJSON
                     * @memberof TW.proto.BinanceSendOrder.Output
                     * @instance
                     * @returns {Object.<string,*>} JSON object
                     */
                    Output.prototype.toJSON = function toJSON() {
                        return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                    };
    
                    return Output;
                })();
    
                return BinanceSendOrder;
            })();
    
            proto.BinanceTokenFreezeOrder = (function() {
    
                /**
                 * Properties of a BinanceTokenFreezeOrder.
                 * @memberof TW.proto
                 * @interface IBinanceTokenFreezeOrder
                 * @property {Uint8Array|null} [from] BinanceTokenFreezeOrder from
                 * @property {string|null} [symbol] BinanceTokenFreezeOrder symbol
                 * @property {Long|null} [amount] BinanceTokenFreezeOrder amount
                 */
    
                /**
                 * Constructs a new BinanceTokenFreezeOrder.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceTokenFreezeOrder.
                 * @implements IBinanceTokenFreezeOrder
                 * @constructor
                 * @param {TW.proto.IBinanceTokenFreezeOrder=} [properties] Properties to set
                 */
                function BinanceTokenFreezeOrder(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceTokenFreezeOrder from.
                 * @member {Uint8Array} from
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @instance
                 */
                BinanceTokenFreezeOrder.prototype.from = $util.newBuffer([]);
    
                /**
                 * BinanceTokenFreezeOrder symbol.
                 * @member {string} symbol
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @instance
                 */
                BinanceTokenFreezeOrder.prototype.symbol = "";
    
                /**
                 * BinanceTokenFreezeOrder amount.
                 * @member {Long} amount
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @instance
                 */
                BinanceTokenFreezeOrder.prototype.amount = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * Creates a new BinanceTokenFreezeOrder instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {TW.proto.IBinanceTokenFreezeOrder=} [properties] Properties to set
                 * @returns {TW.proto.BinanceTokenFreezeOrder} BinanceTokenFreezeOrder instance
                 */
                BinanceTokenFreezeOrder.create = function create(properties) {
                    return new BinanceTokenFreezeOrder(properties);
                };
    
                /**
                 * Encodes the specified BinanceTokenFreezeOrder message. Does not implicitly {@link TW.proto.BinanceTokenFreezeOrder.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {TW.proto.IBinanceTokenFreezeOrder} message BinanceTokenFreezeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTokenFreezeOrder.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.from != null && message.hasOwnProperty("from"))
                        writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.from);
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        writer.uint32(/* id 2, wireType 2 =*/18).string(message.symbol);
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        writer.uint32(/* id 3, wireType 0 =*/24).int64(message.amount);
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceTokenFreezeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceTokenFreezeOrder.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {TW.proto.IBinanceTokenFreezeOrder} message BinanceTokenFreezeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTokenFreezeOrder.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceTokenFreezeOrder message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceTokenFreezeOrder} BinanceTokenFreezeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTokenFreezeOrder.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceTokenFreezeOrder();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.from = reader.bytes();
                            break;
                        case 2:
                            message.symbol = reader.string();
                            break;
                        case 3:
                            message.amount = reader.int64();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceTokenFreezeOrder message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceTokenFreezeOrder} BinanceTokenFreezeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTokenFreezeOrder.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceTokenFreezeOrder message.
                 * @function verify
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceTokenFreezeOrder.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.from != null && message.hasOwnProperty("from"))
                        if (!(message.from && typeof message.from.length === "number" || $util.isString(message.from)))
                            return "from: buffer expected";
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        if (!$util.isString(message.symbol))
                            return "symbol: string expected";
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (!$util.isInteger(message.amount) && !(message.amount && $util.isInteger(message.amount.low) && $util.isInteger(message.amount.high)))
                            return "amount: integer|Long expected";
                    return null;
                };
    
                /**
                 * Creates a BinanceTokenFreezeOrder message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceTokenFreezeOrder} BinanceTokenFreezeOrder
                 */
                BinanceTokenFreezeOrder.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceTokenFreezeOrder)
                        return object;
                    var message = new $root.TW.proto.BinanceTokenFreezeOrder();
                    if (object.from != null)
                        if (typeof object.from === "string")
                            $util.base64.decode(object.from, message.from = $util.newBuffer($util.base64.length(object.from)), 0);
                        else if (object.from.length)
                            message.from = object.from;
                    if (object.symbol != null)
                        message.symbol = String(object.symbol);
                    if (object.amount != null)
                        if ($util.Long)
                            (message.amount = $util.Long.fromValue(object.amount)).unsigned = false;
                        else if (typeof object.amount === "string")
                            message.amount = parseInt(object.amount, 10);
                        else if (typeof object.amount === "number")
                            message.amount = object.amount;
                        else if (typeof object.amount === "object")
                            message.amount = new $util.LongBits(object.amount.low >>> 0, object.amount.high >>> 0).toNumber();
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceTokenFreezeOrder message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @static
                 * @param {TW.proto.BinanceTokenFreezeOrder} message BinanceTokenFreezeOrder
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceTokenFreezeOrder.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if (options.bytes === String)
                            object.from = "";
                        else {
                            object.from = [];
                            if (options.bytes !== Array)
                                object.from = $util.newBuffer(object.from);
                        }
                        object.symbol = "";
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.amount = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.amount = options.longs === String ? "0" : 0;
                    }
                    if (message.from != null && message.hasOwnProperty("from"))
                        object.from = options.bytes === String ? $util.base64.encode(message.from, 0, message.from.length) : options.bytes === Array ? Array.prototype.slice.call(message.from) : message.from;
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        object.symbol = message.symbol;
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (typeof message.amount === "number")
                            object.amount = options.longs === String ? String(message.amount) : message.amount;
                        else
                            object.amount = options.longs === String ? $util.Long.prototype.toString.call(message.amount) : options.longs === Number ? new $util.LongBits(message.amount.low >>> 0, message.amount.high >>> 0).toNumber() : message.amount;
                    return object;
                };
    
                /**
                 * Converts this BinanceTokenFreezeOrder to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceTokenFreezeOrder
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceTokenFreezeOrder.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BinanceTokenFreezeOrder;
            })();
    
            proto.BinanceTokenUnfreezeOrder = (function() {
    
                /**
                 * Properties of a BinanceTokenUnfreezeOrder.
                 * @memberof TW.proto
                 * @interface IBinanceTokenUnfreezeOrder
                 * @property {Uint8Array|null} [from] BinanceTokenUnfreezeOrder from
                 * @property {string|null} [symbol] BinanceTokenUnfreezeOrder symbol
                 * @property {Long|null} [amount] BinanceTokenUnfreezeOrder amount
                 */
    
                /**
                 * Constructs a new BinanceTokenUnfreezeOrder.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceTokenUnfreezeOrder.
                 * @implements IBinanceTokenUnfreezeOrder
                 * @constructor
                 * @param {TW.proto.IBinanceTokenUnfreezeOrder=} [properties] Properties to set
                 */
                function BinanceTokenUnfreezeOrder(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceTokenUnfreezeOrder from.
                 * @member {Uint8Array} from
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @instance
                 */
                BinanceTokenUnfreezeOrder.prototype.from = $util.newBuffer([]);
    
                /**
                 * BinanceTokenUnfreezeOrder symbol.
                 * @member {string} symbol
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @instance
                 */
                BinanceTokenUnfreezeOrder.prototype.symbol = "";
    
                /**
                 * BinanceTokenUnfreezeOrder amount.
                 * @member {Long} amount
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @instance
                 */
                BinanceTokenUnfreezeOrder.prototype.amount = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * Creates a new BinanceTokenUnfreezeOrder instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {TW.proto.IBinanceTokenUnfreezeOrder=} [properties] Properties to set
                 * @returns {TW.proto.BinanceTokenUnfreezeOrder} BinanceTokenUnfreezeOrder instance
                 */
                BinanceTokenUnfreezeOrder.create = function create(properties) {
                    return new BinanceTokenUnfreezeOrder(properties);
                };
    
                /**
                 * Encodes the specified BinanceTokenUnfreezeOrder message. Does not implicitly {@link TW.proto.BinanceTokenUnfreezeOrder.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {TW.proto.IBinanceTokenUnfreezeOrder} message BinanceTokenUnfreezeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTokenUnfreezeOrder.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.from != null && message.hasOwnProperty("from"))
                        writer.uint32(/* id 1, wireType 2 =*/10).bytes(message.from);
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        writer.uint32(/* id 2, wireType 2 =*/18).string(message.symbol);
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        writer.uint32(/* id 3, wireType 0 =*/24).int64(message.amount);
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceTokenUnfreezeOrder message, length delimited. Does not implicitly {@link TW.proto.BinanceTokenUnfreezeOrder.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {TW.proto.IBinanceTokenUnfreezeOrder} message BinanceTokenUnfreezeOrder message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceTokenUnfreezeOrder.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceTokenUnfreezeOrder message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceTokenUnfreezeOrder} BinanceTokenUnfreezeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTokenUnfreezeOrder.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceTokenUnfreezeOrder();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.from = reader.bytes();
                            break;
                        case 2:
                            message.symbol = reader.string();
                            break;
                        case 3:
                            message.amount = reader.int64();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceTokenUnfreezeOrder message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceTokenUnfreezeOrder} BinanceTokenUnfreezeOrder
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceTokenUnfreezeOrder.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceTokenUnfreezeOrder message.
                 * @function verify
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceTokenUnfreezeOrder.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.from != null && message.hasOwnProperty("from"))
                        if (!(message.from && typeof message.from.length === "number" || $util.isString(message.from)))
                            return "from: buffer expected";
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        if (!$util.isString(message.symbol))
                            return "symbol: string expected";
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (!$util.isInteger(message.amount) && !(message.amount && $util.isInteger(message.amount.low) && $util.isInteger(message.amount.high)))
                            return "amount: integer|Long expected";
                    return null;
                };
    
                /**
                 * Creates a BinanceTokenUnfreezeOrder message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceTokenUnfreezeOrder} BinanceTokenUnfreezeOrder
                 */
                BinanceTokenUnfreezeOrder.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceTokenUnfreezeOrder)
                        return object;
                    var message = new $root.TW.proto.BinanceTokenUnfreezeOrder();
                    if (object.from != null)
                        if (typeof object.from === "string")
                            $util.base64.decode(object.from, message.from = $util.newBuffer($util.base64.length(object.from)), 0);
                        else if (object.from.length)
                            message.from = object.from;
                    if (object.symbol != null)
                        message.symbol = String(object.symbol);
                    if (object.amount != null)
                        if ($util.Long)
                            (message.amount = $util.Long.fromValue(object.amount)).unsigned = false;
                        else if (typeof object.amount === "string")
                            message.amount = parseInt(object.amount, 10);
                        else if (typeof object.amount === "number")
                            message.amount = object.amount;
                        else if (typeof object.amount === "object")
                            message.amount = new $util.LongBits(object.amount.low >>> 0, object.amount.high >>> 0).toNumber();
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceTokenUnfreezeOrder message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @static
                 * @param {TW.proto.BinanceTokenUnfreezeOrder} message BinanceTokenUnfreezeOrder
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceTokenUnfreezeOrder.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        if (options.bytes === String)
                            object.from = "";
                        else {
                            object.from = [];
                            if (options.bytes !== Array)
                                object.from = $util.newBuffer(object.from);
                        }
                        object.symbol = "";
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.amount = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.amount = options.longs === String ? "0" : 0;
                    }
                    if (message.from != null && message.hasOwnProperty("from"))
                        object.from = options.bytes === String ? $util.base64.encode(message.from, 0, message.from.length) : options.bytes === Array ? Array.prototype.slice.call(message.from) : message.from;
                    if (message.symbol != null && message.hasOwnProperty("symbol"))
                        object.symbol = message.symbol;
                    if (message.amount != null && message.hasOwnProperty("amount"))
                        if (typeof message.amount === "number")
                            object.amount = options.longs === String ? String(message.amount) : message.amount;
                        else
                            object.amount = options.longs === String ? $util.Long.prototype.toString.call(message.amount) : options.longs === Number ? new $util.LongBits(message.amount.low >>> 0, message.amount.high >>> 0).toNumber() : message.amount;
                    return object;
                };
    
                /**
                 * Converts this BinanceTokenUnfreezeOrder to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceTokenUnfreezeOrder
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceTokenUnfreezeOrder.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BinanceTokenUnfreezeOrder;
            })();
    
            proto.BinanceSigningInput = (function() {
    
                /**
                 * Properties of a BinanceSigningInput.
                 * @memberof TW.proto
                 * @interface IBinanceSigningInput
                 * @property {string|null} [chainId] BinanceSigningInput chainId
                 * @property {Long|null} [accountNumber] BinanceSigningInput accountNumber
                 * @property {Long|null} [sequence] BinanceSigningInput sequence
                 * @property {Long|null} [source] BinanceSigningInput source
                 * @property {string|null} [memo] BinanceSigningInput memo
                 * @property {Uint8Array|null} [privateKey] BinanceSigningInput privateKey
                 * @property {TW.proto.IBinanceTradeOrder|null} [tradeOrder] BinanceSigningInput tradeOrder
                 * @property {TW.proto.IBinanceCancelTradeOrder|null} [cancelTradeOrder] BinanceSigningInput cancelTradeOrder
                 * @property {TW.proto.IBinanceSendOrder|null} [sendOrder] BinanceSigningInput sendOrder
                 * @property {TW.proto.IBinanceTokenFreezeOrder|null} [freezeOrder] BinanceSigningInput freezeOrder
                 * @property {TW.proto.IBinanceTokenUnfreezeOrder|null} [unfreezeOrder] BinanceSigningInput unfreezeOrder
                 */
    
                /**
                 * Constructs a new BinanceSigningInput.
                 * @memberof TW.proto
                 * @classdesc Represents a BinanceSigningInput.
                 * @implements IBinanceSigningInput
                 * @constructor
                 * @param {TW.proto.IBinanceSigningInput=} [properties] Properties to set
                 */
                function BinanceSigningInput(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * BinanceSigningInput chainId.
                 * @member {string} chainId
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.chainId = "";
    
                /**
                 * BinanceSigningInput accountNumber.
                 * @member {Long} accountNumber
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.accountNumber = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceSigningInput sequence.
                 * @member {Long} sequence
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.sequence = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceSigningInput source.
                 * @member {Long} source
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.source = $util.Long ? $util.Long.fromBits(0,0,false) : 0;
    
                /**
                 * BinanceSigningInput memo.
                 * @member {string} memo
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.memo = "";
    
                /**
                 * BinanceSigningInput privateKey.
                 * @member {Uint8Array} privateKey
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.privateKey = $util.newBuffer([]);
    
                /**
                 * BinanceSigningInput tradeOrder.
                 * @member {TW.proto.IBinanceTradeOrder|null|undefined} tradeOrder
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.tradeOrder = null;
    
                /**
                 * BinanceSigningInput cancelTradeOrder.
                 * @member {TW.proto.IBinanceCancelTradeOrder|null|undefined} cancelTradeOrder
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.cancelTradeOrder = null;
    
                /**
                 * BinanceSigningInput sendOrder.
                 * @member {TW.proto.IBinanceSendOrder|null|undefined} sendOrder
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.sendOrder = null;
    
                /**
                 * BinanceSigningInput freezeOrder.
                 * @member {TW.proto.IBinanceTokenFreezeOrder|null|undefined} freezeOrder
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.freezeOrder = null;
    
                /**
                 * BinanceSigningInput unfreezeOrder.
                 * @member {TW.proto.IBinanceTokenUnfreezeOrder|null|undefined} unfreezeOrder
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                BinanceSigningInput.prototype.unfreezeOrder = null;
    
                // OneOf field names bound to virtual getters and setters
                var $oneOfFields;
    
                /**
                 * BinanceSigningInput orderOneof.
                 * @member {"tradeOrder"|"cancelTradeOrder"|"sendOrder"|"freezeOrder"|"unfreezeOrder"|undefined} orderOneof
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 */
                Object.defineProperty(BinanceSigningInput.prototype, "orderOneof", {
                    get: $util.oneOfGetter($oneOfFields = ["tradeOrder", "cancelTradeOrder", "sendOrder", "freezeOrder", "unfreezeOrder"]),
                    set: $util.oneOfSetter($oneOfFields)
                });
    
                /**
                 * Creates a new BinanceSigningInput instance using the specified properties.
                 * @function create
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {TW.proto.IBinanceSigningInput=} [properties] Properties to set
                 * @returns {TW.proto.BinanceSigningInput} BinanceSigningInput instance
                 */
                BinanceSigningInput.create = function create(properties) {
                    return new BinanceSigningInput(properties);
                };
    
                /**
                 * Encodes the specified BinanceSigningInput message. Does not implicitly {@link TW.proto.BinanceSigningInput.verify|verify} messages.
                 * @function encode
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {TW.proto.IBinanceSigningInput} message BinanceSigningInput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceSigningInput.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.chainId != null && message.hasOwnProperty("chainId"))
                        writer.uint32(/* id 1, wireType 2 =*/10).string(message.chainId);
                    if (message.accountNumber != null && message.hasOwnProperty("accountNumber"))
                        writer.uint32(/* id 2, wireType 0 =*/16).int64(message.accountNumber);
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        writer.uint32(/* id 3, wireType 0 =*/24).int64(message.sequence);
                    if (message.source != null && message.hasOwnProperty("source"))
                        writer.uint32(/* id 4, wireType 0 =*/32).int64(message.source);
                    if (message.memo != null && message.hasOwnProperty("memo"))
                        writer.uint32(/* id 5, wireType 2 =*/42).string(message.memo);
                    if (message.privateKey != null && message.hasOwnProperty("privateKey"))
                        writer.uint32(/* id 6, wireType 2 =*/50).bytes(message.privateKey);
                    if (message.tradeOrder != null && message.hasOwnProperty("tradeOrder"))
                        $root.TW.proto.BinanceTradeOrder.encode(message.tradeOrder, writer.uint32(/* id 7, wireType 2 =*/58).fork()).ldelim();
                    if (message.cancelTradeOrder != null && message.hasOwnProperty("cancelTradeOrder"))
                        $root.TW.proto.BinanceCancelTradeOrder.encode(message.cancelTradeOrder, writer.uint32(/* id 8, wireType 2 =*/66).fork()).ldelim();
                    if (message.sendOrder != null && message.hasOwnProperty("sendOrder"))
                        $root.TW.proto.BinanceSendOrder.encode(message.sendOrder, writer.uint32(/* id 9, wireType 2 =*/74).fork()).ldelim();
                    if (message.freezeOrder != null && message.hasOwnProperty("freezeOrder"))
                        $root.TW.proto.BinanceTokenFreezeOrder.encode(message.freezeOrder, writer.uint32(/* id 10, wireType 2 =*/82).fork()).ldelim();
                    if (message.unfreezeOrder != null && message.hasOwnProperty("unfreezeOrder"))
                        $root.TW.proto.BinanceTokenUnfreezeOrder.encode(message.unfreezeOrder, writer.uint32(/* id 11, wireType 2 =*/90).fork()).ldelim();
                    return writer;
                };
    
                /**
                 * Encodes the specified BinanceSigningInput message, length delimited. Does not implicitly {@link TW.proto.BinanceSigningInput.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {TW.proto.IBinanceSigningInput} message BinanceSigningInput message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                BinanceSigningInput.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes a BinanceSigningInput message from the specified reader or buffer.
                 * @function decode
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {TW.proto.BinanceSigningInput} BinanceSigningInput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceSigningInput.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.TW.proto.BinanceSigningInput();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.chainId = reader.string();
                            break;
                        case 2:
                            message.accountNumber = reader.int64();
                            break;
                        case 3:
                            message.sequence = reader.int64();
                            break;
                        case 4:
                            message.source = reader.int64();
                            break;
                        case 5:
                            message.memo = reader.string();
                            break;
                        case 6:
                            message.privateKey = reader.bytes();
                            break;
                        case 7:
                            message.tradeOrder = $root.TW.proto.BinanceTradeOrder.decode(reader, reader.uint32());
                            break;
                        case 8:
                            message.cancelTradeOrder = $root.TW.proto.BinanceCancelTradeOrder.decode(reader, reader.uint32());
                            break;
                        case 9:
                            message.sendOrder = $root.TW.proto.BinanceSendOrder.decode(reader, reader.uint32());
                            break;
                        case 10:
                            message.freezeOrder = $root.TW.proto.BinanceTokenFreezeOrder.decode(reader, reader.uint32());
                            break;
                        case 11:
                            message.unfreezeOrder = $root.TW.proto.BinanceTokenUnfreezeOrder.decode(reader, reader.uint32());
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes a BinanceSigningInput message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {TW.proto.BinanceSigningInput} BinanceSigningInput
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                BinanceSigningInput.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies a BinanceSigningInput message.
                 * @function verify
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                BinanceSigningInput.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    var properties = {};
                    if (message.chainId != null && message.hasOwnProperty("chainId"))
                        if (!$util.isString(message.chainId))
                            return "chainId: string expected";
                    if (message.accountNumber != null && message.hasOwnProperty("accountNumber"))
                        if (!$util.isInteger(message.accountNumber) && !(message.accountNumber && $util.isInteger(message.accountNumber.low) && $util.isInteger(message.accountNumber.high)))
                            return "accountNumber: integer|Long expected";
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        if (!$util.isInteger(message.sequence) && !(message.sequence && $util.isInteger(message.sequence.low) && $util.isInteger(message.sequence.high)))
                            return "sequence: integer|Long expected";
                    if (message.source != null && message.hasOwnProperty("source"))
                        if (!$util.isInteger(message.source) && !(message.source && $util.isInteger(message.source.low) && $util.isInteger(message.source.high)))
                            return "source: integer|Long expected";
                    if (message.memo != null && message.hasOwnProperty("memo"))
                        if (!$util.isString(message.memo))
                            return "memo: string expected";
                    if (message.privateKey != null && message.hasOwnProperty("privateKey"))
                        if (!(message.privateKey && typeof message.privateKey.length === "number" || $util.isString(message.privateKey)))
                            return "privateKey: buffer expected";
                    if (message.tradeOrder != null && message.hasOwnProperty("tradeOrder")) {
                        properties.orderOneof = 1;
                        {
                            var error = $root.TW.proto.BinanceTradeOrder.verify(message.tradeOrder);
                            if (error)
                                return "tradeOrder." + error;
                        }
                    }
                    if (message.cancelTradeOrder != null && message.hasOwnProperty("cancelTradeOrder")) {
                        if (properties.orderOneof === 1)
                            return "orderOneof: multiple values";
                        properties.orderOneof = 1;
                        {
                            var error = $root.TW.proto.BinanceCancelTradeOrder.verify(message.cancelTradeOrder);
                            if (error)
                                return "cancelTradeOrder." + error;
                        }
                    }
                    if (message.sendOrder != null && message.hasOwnProperty("sendOrder")) {
                        if (properties.orderOneof === 1)
                            return "orderOneof: multiple values";
                        properties.orderOneof = 1;
                        {
                            var error = $root.TW.proto.BinanceSendOrder.verify(message.sendOrder);
                            if (error)
                                return "sendOrder." + error;
                        }
                    }
                    if (message.freezeOrder != null && message.hasOwnProperty("freezeOrder")) {
                        if (properties.orderOneof === 1)
                            return "orderOneof: multiple values";
                        properties.orderOneof = 1;
                        {
                            var error = $root.TW.proto.BinanceTokenFreezeOrder.verify(message.freezeOrder);
                            if (error)
                                return "freezeOrder." + error;
                        }
                    }
                    if (message.unfreezeOrder != null && message.hasOwnProperty("unfreezeOrder")) {
                        if (properties.orderOneof === 1)
                            return "orderOneof: multiple values";
                        properties.orderOneof = 1;
                        {
                            var error = $root.TW.proto.BinanceTokenUnfreezeOrder.verify(message.unfreezeOrder);
                            if (error)
                                return "unfreezeOrder." + error;
                        }
                    }
                    return null;
                };
    
                /**
                 * Creates a BinanceSigningInput message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {TW.proto.BinanceSigningInput} BinanceSigningInput
                 */
                BinanceSigningInput.fromObject = function fromObject(object) {
                    if (object instanceof $root.TW.proto.BinanceSigningInput)
                        return object;
                    var message = new $root.TW.proto.BinanceSigningInput();
                    if (object.chainId != null)
                        message.chainId = String(object.chainId);
                    if (object.accountNumber != null)
                        if ($util.Long)
                            (message.accountNumber = $util.Long.fromValue(object.accountNumber)).unsigned = false;
                        else if (typeof object.accountNumber === "string")
                            message.accountNumber = parseInt(object.accountNumber, 10);
                        else if (typeof object.accountNumber === "number")
                            message.accountNumber = object.accountNumber;
                        else if (typeof object.accountNumber === "object")
                            message.accountNumber = new $util.LongBits(object.accountNumber.low >>> 0, object.accountNumber.high >>> 0).toNumber();
                    if (object.sequence != null)
                        if ($util.Long)
                            (message.sequence = $util.Long.fromValue(object.sequence)).unsigned = false;
                        else if (typeof object.sequence === "string")
                            message.sequence = parseInt(object.sequence, 10);
                        else if (typeof object.sequence === "number")
                            message.sequence = object.sequence;
                        else if (typeof object.sequence === "object")
                            message.sequence = new $util.LongBits(object.sequence.low >>> 0, object.sequence.high >>> 0).toNumber();
                    if (object.source != null)
                        if ($util.Long)
                            (message.source = $util.Long.fromValue(object.source)).unsigned = false;
                        else if (typeof object.source === "string")
                            message.source = parseInt(object.source, 10);
                        else if (typeof object.source === "number")
                            message.source = object.source;
                        else if (typeof object.source === "object")
                            message.source = new $util.LongBits(object.source.low >>> 0, object.source.high >>> 0).toNumber();
                    if (object.memo != null)
                        message.memo = String(object.memo);
                    if (object.privateKey != null)
                        if (typeof object.privateKey === "string")
                            $util.base64.decode(object.privateKey, message.privateKey = $util.newBuffer($util.base64.length(object.privateKey)), 0);
                        else if (object.privateKey.length)
                            message.privateKey = object.privateKey;
                    if (object.tradeOrder != null) {
                        if (typeof object.tradeOrder !== "object")
                            throw TypeError(".TW.proto.BinanceSigningInput.tradeOrder: object expected");
                        message.tradeOrder = $root.TW.proto.BinanceTradeOrder.fromObject(object.tradeOrder);
                    }
                    if (object.cancelTradeOrder != null) {
                        if (typeof object.cancelTradeOrder !== "object")
                            throw TypeError(".TW.proto.BinanceSigningInput.cancelTradeOrder: object expected");
                        message.cancelTradeOrder = $root.TW.proto.BinanceCancelTradeOrder.fromObject(object.cancelTradeOrder);
                    }
                    if (object.sendOrder != null) {
                        if (typeof object.sendOrder !== "object")
                            throw TypeError(".TW.proto.BinanceSigningInput.sendOrder: object expected");
                        message.sendOrder = $root.TW.proto.BinanceSendOrder.fromObject(object.sendOrder);
                    }
                    if (object.freezeOrder != null) {
                        if (typeof object.freezeOrder !== "object")
                            throw TypeError(".TW.proto.BinanceSigningInput.freezeOrder: object expected");
                        message.freezeOrder = $root.TW.proto.BinanceTokenFreezeOrder.fromObject(object.freezeOrder);
                    }
                    if (object.unfreezeOrder != null) {
                        if (typeof object.unfreezeOrder !== "object")
                            throw TypeError(".TW.proto.BinanceSigningInput.unfreezeOrder: object expected");
                        message.unfreezeOrder = $root.TW.proto.BinanceTokenUnfreezeOrder.fromObject(object.unfreezeOrder);
                    }
                    return message;
                };
    
                /**
                 * Creates a plain object from a BinanceSigningInput message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof TW.proto.BinanceSigningInput
                 * @static
                 * @param {TW.proto.BinanceSigningInput} message BinanceSigningInput
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                BinanceSigningInput.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        object.chainId = "";
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.accountNumber = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.accountNumber = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.sequence = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.sequence = options.longs === String ? "0" : 0;
                        if ($util.Long) {
                            var long = new $util.Long(0, 0, false);
                            object.source = options.longs === String ? long.toString() : options.longs === Number ? long.toNumber() : long;
                        } else
                            object.source = options.longs === String ? "0" : 0;
                        object.memo = "";
                        if (options.bytes === String)
                            object.privateKey = "";
                        else {
                            object.privateKey = [];
                            if (options.bytes !== Array)
                                object.privateKey = $util.newBuffer(object.privateKey);
                        }
                    }
                    if (message.chainId != null && message.hasOwnProperty("chainId"))
                        object.chainId = message.chainId;
                    if (message.accountNumber != null && message.hasOwnProperty("accountNumber"))
                        if (typeof message.accountNumber === "number")
                            object.accountNumber = options.longs === String ? String(message.accountNumber) : message.accountNumber;
                        else
                            object.accountNumber = options.longs === String ? $util.Long.prototype.toString.call(message.accountNumber) : options.longs === Number ? new $util.LongBits(message.accountNumber.low >>> 0, message.accountNumber.high >>> 0).toNumber() : message.accountNumber;
                    if (message.sequence != null && message.hasOwnProperty("sequence"))
                        if (typeof message.sequence === "number")
                            object.sequence = options.longs === String ? String(message.sequence) : message.sequence;
                        else
                            object.sequence = options.longs === String ? $util.Long.prototype.toString.call(message.sequence) : options.longs === Number ? new $util.LongBits(message.sequence.low >>> 0, message.sequence.high >>> 0).toNumber() : message.sequence;
                    if (message.source != null && message.hasOwnProperty("source"))
                        if (typeof message.source === "number")
                            object.source = options.longs === String ? String(message.source) : message.source;
                        else
                            object.source = options.longs === String ? $util.Long.prototype.toString.call(message.source) : options.longs === Number ? new $util.LongBits(message.source.low >>> 0, message.source.high >>> 0).toNumber() : message.source;
                    if (message.memo != null && message.hasOwnProperty("memo"))
                        object.memo = message.memo;
                    if (message.privateKey != null && message.hasOwnProperty("privateKey"))
                        object.privateKey = options.bytes === String ? $util.base64.encode(message.privateKey, 0, message.privateKey.length) : options.bytes === Array ? Array.prototype.slice.call(message.privateKey) : message.privateKey;
                    if (message.tradeOrder != null && message.hasOwnProperty("tradeOrder")) {
                        object.tradeOrder = $root.TW.proto.BinanceTradeOrder.toObject(message.tradeOrder, options);
                        if (options.oneofs)
                            object.orderOneof = "tradeOrder";
                    }
                    if (message.cancelTradeOrder != null && message.hasOwnProperty("cancelTradeOrder")) {
                        object.cancelTradeOrder = $root.TW.proto.BinanceCancelTradeOrder.toObject(message.cancelTradeOrder, options);
                        if (options.oneofs)
                            object.orderOneof = "cancelTradeOrder";
                    }
                    if (message.sendOrder != null && message.hasOwnProperty("sendOrder")) {
                        object.sendOrder = $root.TW.proto.BinanceSendOrder.toObject(message.sendOrder, options);
                        if (options.oneofs)
                            object.orderOneof = "sendOrder";
                    }
                    if (message.freezeOrder != null && message.hasOwnProperty("freezeOrder")) {
                        object.freezeOrder = $root.TW.proto.BinanceTokenFreezeOrder.toObject(message.freezeOrder, options);
                        if (options.oneofs)
                            object.orderOneof = "freezeOrder";
                    }
                    if (message.unfreezeOrder != null && message.hasOwnProperty("unfreezeOrder")) {
                        object.unfreezeOrder = $root.TW.proto.BinanceTokenUnfreezeOrder.toObject(message.unfreezeOrder, options);
                        if (options.oneofs)
                            object.orderOneof = "unfreezeOrder";
                    }
                    return object;
                };
    
                /**
                 * Converts this BinanceSigningInput to JSON.
                 * @function toJSON
                 * @memberof TW.proto.BinanceSigningInput
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                BinanceSigningInput.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return BinanceSigningInput;
            })();
    
            return proto;
        })();
    
        return TW;
    })();
    
    $root.google = (function() {
    
        /**
         * Namespace google.
         * @exports google
         * @namespace
         */
        var google = {};
    
        google.protobuf = (function() {
    
            /**
             * Namespace protobuf.
             * @memberof google
             * @namespace
             */
            var protobuf = {};
    
            protobuf.Any = (function() {
    
                /**
                 * Properties of an Any.
                 * @memberof google.protobuf
                 * @interface IAny
                 * @property {string|null} [type_url] Any type_url
                 * @property {Uint8Array|null} [value] Any value
                 */
    
                /**
                 * Constructs a new Any.
                 * @memberof google.protobuf
                 * @classdesc Represents an Any.
                 * @implements IAny
                 * @constructor
                 * @param {google.protobuf.IAny=} [properties] Properties to set
                 */
                function Any(properties) {
                    if (properties)
                        for (var keys = Object.keys(properties), i = 0; i < keys.length; ++i)
                            if (properties[keys[i]] != null)
                                this[keys[i]] = properties[keys[i]];
                }
    
                /**
                 * Any type_url.
                 * @member {string} type_url
                 * @memberof google.protobuf.Any
                 * @instance
                 */
                Any.prototype.type_url = "";
    
                /**
                 * Any value.
                 * @member {Uint8Array} value
                 * @memberof google.protobuf.Any
                 * @instance
                 */
                Any.prototype.value = $util.newBuffer([]);
    
                /**
                 * Creates a new Any instance using the specified properties.
                 * @function create
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {google.protobuf.IAny=} [properties] Properties to set
                 * @returns {google.protobuf.Any} Any instance
                 */
                Any.create = function create(properties) {
                    return new Any(properties);
                };
    
                /**
                 * Encodes the specified Any message. Does not implicitly {@link google.protobuf.Any.verify|verify} messages.
                 * @function encode
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {google.protobuf.IAny} message Any message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                Any.encode = function encode(message, writer) {
                    if (!writer)
                        writer = $Writer.create();
                    if (message.type_url != null && message.hasOwnProperty("type_url"))
                        writer.uint32(/* id 1, wireType 2 =*/10).string(message.type_url);
                    if (message.value != null && message.hasOwnProperty("value"))
                        writer.uint32(/* id 2, wireType 2 =*/18).bytes(message.value);
                    return writer;
                };
    
                /**
                 * Encodes the specified Any message, length delimited. Does not implicitly {@link google.protobuf.Any.verify|verify} messages.
                 * @function encodeDelimited
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {google.protobuf.IAny} message Any message or plain object to encode
                 * @param {$protobuf.Writer} [writer] Writer to encode to
                 * @returns {$protobuf.Writer} Writer
                 */
                Any.encodeDelimited = function encodeDelimited(message, writer) {
                    return this.encode(message, writer).ldelim();
                };
    
                /**
                 * Decodes an Any message from the specified reader or buffer.
                 * @function decode
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @param {number} [length] Message length if known beforehand
                 * @returns {google.protobuf.Any} Any
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                Any.decode = function decode(reader, length) {
                    if (!(reader instanceof $Reader))
                        reader = $Reader.create(reader);
                    var end = length === undefined ? reader.len : reader.pos + length, message = new $root.google.protobuf.Any();
                    while (reader.pos < end) {
                        var tag = reader.uint32();
                        switch (tag >>> 3) {
                        case 1:
                            message.type_url = reader.string();
                            break;
                        case 2:
                            message.value = reader.bytes();
                            break;
                        default:
                            reader.skipType(tag & 7);
                            break;
                        }
                    }
                    return message;
                };
    
                /**
                 * Decodes an Any message from the specified reader or buffer, length delimited.
                 * @function decodeDelimited
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {$protobuf.Reader|Uint8Array} reader Reader or buffer to decode from
                 * @returns {google.protobuf.Any} Any
                 * @throws {Error} If the payload is not a reader or valid buffer
                 * @throws {$protobuf.util.ProtocolError} If required fields are missing
                 */
                Any.decodeDelimited = function decodeDelimited(reader) {
                    if (!(reader instanceof $Reader))
                        reader = new $Reader(reader);
                    return this.decode(reader, reader.uint32());
                };
    
                /**
                 * Verifies an Any message.
                 * @function verify
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {Object.<string,*>} message Plain object to verify
                 * @returns {string|null} `null` if valid, otherwise the reason why it is not
                 */
                Any.verify = function verify(message) {
                    if (typeof message !== "object" || message === null)
                        return "object expected";
                    if (message.type_url != null && message.hasOwnProperty("type_url"))
                        if (!$util.isString(message.type_url))
                            return "type_url: string expected";
                    if (message.value != null && message.hasOwnProperty("value"))
                        if (!(message.value && typeof message.value.length === "number" || $util.isString(message.value)))
                            return "value: buffer expected";
                    return null;
                };
    
                /**
                 * Creates an Any message from a plain object. Also converts values to their respective internal types.
                 * @function fromObject
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {Object.<string,*>} object Plain object
                 * @returns {google.protobuf.Any} Any
                 */
                Any.fromObject = function fromObject(object) {
                    if (object instanceof $root.google.protobuf.Any)
                        return object;
                    var message = new $root.google.protobuf.Any();
                    if (object.type_url != null)
                        message.type_url = String(object.type_url);
                    if (object.value != null)
                        if (typeof object.value === "string")
                            $util.base64.decode(object.value, message.value = $util.newBuffer($util.base64.length(object.value)), 0);
                        else if (object.value.length)
                            message.value = object.value;
                    return message;
                };
    
                /**
                 * Creates a plain object from an Any message. Also converts values to other types if specified.
                 * @function toObject
                 * @memberof google.protobuf.Any
                 * @static
                 * @param {google.protobuf.Any} message Any
                 * @param {$protobuf.IConversionOptions} [options] Conversion options
                 * @returns {Object.<string,*>} Plain object
                 */
                Any.toObject = function toObject(message, options) {
                    if (!options)
                        options = {};
                    var object = {};
                    if (options.defaults) {
                        object.type_url = "";
                        if (options.bytes === String)
                            object.value = "";
                        else {
                            object.value = [];
                            if (options.bytes !== Array)
                                object.value = $util.newBuffer(object.value);
                        }
                    }
                    if (message.type_url != null && message.hasOwnProperty("type_url"))
                        object.type_url = message.type_url;
                    if (message.value != null && message.hasOwnProperty("value"))
                        object.value = options.bytes === String ? $util.base64.encode(message.value, 0, message.value.length) : options.bytes === Array ? Array.prototype.slice.call(message.value) : message.value;
                    return object;
                };
    
                /**
                 * Converts this Any to JSON.
                 * @function toJSON
                 * @memberof google.protobuf.Any
                 * @instance
                 * @returns {Object.<string,*>} JSON object
                 */
                Any.prototype.toJSON = function toJSON() {
                    return this.constructor.toObject(this, $protobuf.util.toJSONOptions);
                };
    
                return Any;
            })();
    
            return protobuf;
        })();
    
        return google;
    })();

    return $root;
});
