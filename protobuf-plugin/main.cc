#include <google/protobuf/compiler/code_generator.h>
#include <google/protobuf/compiler/plugin.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream.h>

using namespace google::protobuf;

class Generator : public  compiler::CodeGenerator {
    std::string GetOutputFilename(const std::string& proto_file) const {
        return "TWProto.h";
    }

    bool Generate(const FileDescriptor* file, const std::string& parameter, compiler::GeneratorContext* generator_context, string* error) const {
        std::unique_ptr<io::ZeroCopyOutputStream> output(generator_context->Open(GetOutputFilename(file->name())));
        io::Printer printer(output.get(), '$');
        
        printer.Print(
            "// Copyright © 2017-2018 Trust.\n"
            "//\n"
            "// This file is part of Trust. The full Trust copyright notice, including\n"
            "// terms governing use, modification, and redistribution, is contained in the\n"
            "// file LICENSE at the root of the source code distribution tree.\n"
            "\n"
            "#pragma once\n"
            "\n"
            "#include \"TWData.h\"\n"
            "\n"
        );
        for (int i = 0; i < file->message_type_count(); i += 1) {
            auto message = file->message_type(i);
            printer.Print("typedef TWData *_Nonnull Proto$name$;\n", "name", message->name());
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
  Generator generator;
  return compiler::PluginMain(argc, argv, &generator);
}
