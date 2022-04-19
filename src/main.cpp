#include <iostream>
#include "student.pb.h"
#include <google/protobuf/text_format.h>
#include <string>

using namespace proto_files;
using namespace google::protobuf;

void PrintProtoMsg(const google::protobuf::Message &message);

int main() {
    proto_files::teacher *tcr = new proto_files::teacher();
    tcr->set_age(10);
    tcr->set_name("teacher");
    proto_files::student *student = tcr->add_sdt();
    student->set_name("student1");
    student->set_age(45);
    student = tcr->add_sdt();
    student->set_name("student2");
    student->set_age(20);

//    string str = "";
//    google::protobuf::TextFormat::PrintToString(*tcr, &str);

    PrintProtoMsg(*tcr);
//    std::cout << str << std::endl;
}

void PrintProtoMsg(const google::protobuf::Message &message) {
    const google::protobuf::Descriptor *des = message.GetDescriptor();
    const google::protobuf::Reflection *ref = message.GetReflection();
    int fieldCount = des->field_count();
    for (int i = 0; i < fieldCount; i++) {
        ///< get field with index i
        const google::protobuf::FieldDescriptor *field = des->field(i);
        switch (field->type()) {
            case google::protobuf::FieldDescriptor::Type::TYPE_INT32:
            case google::protobuf::FieldDescriptor::Type::TYPE_SINT32:
            case google::protobuf::FieldDescriptor::Type::TYPE_SFIXED32: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        int32_t data = ref->GetRepeatedInt32(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    int32_t data = ref->GetInt32(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_INT64:
            case google::protobuf::FieldDescriptor::Type::TYPE_SINT64:
            case google::protobuf::FieldDescriptor::Type::TYPE_SFIXED64: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        int64_t data = ref->GetRepeatedInt64(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    int64_t data = ref->GetInt64(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_UINT32:
            case google::protobuf::FieldDescriptor::Type::TYPE_FIXED32: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        uint32_t data = ref->GetRepeatedUInt32(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    uint32_t data = ref->GetUInt32(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_UINT64:
            case google::protobuf::FieldDescriptor::Type::TYPE_FIXED64: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        uint32_t data = ref->GetRepeatedUInt64(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    uint32_t data = ref->GetUInt64(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_DOUBLE: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        double data = ref->GetRepeatedDouble(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    double data = ref->GetDouble(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_FLOAT: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        float data = ref->GetRepeatedFloat(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    float data = ref->GetFloat(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_BOOL: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        bool data = ref->GetRepeatedBool(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    bool data = ref->GetBool(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_ENUM: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        const google::protobuf::EnumValueDescriptor *data = ref->GetRepeatedEnum(message, field, j);
                        std::cout << data << ",";
                    }
                } else {
                    const google::protobuf::EnumValueDescriptor *data = ref->GetEnum(message, field);
                    std::cout << data->number() << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_STRING:
            case google::protobuf::FieldDescriptor::Type::TYPE_BYTES: {
                if (field->is_repeated()) {
                    std::string data = ref->GetString(message, field);
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        std::cout << data << ",";
                    }
                } else {
                    std::string data = ref->GetString(message, field);
                    std::cout << data << ",";
                }
            }
                break;
            case google::protobuf::FieldDescriptor::Type::TYPE_MESSAGE: {
                if (field->is_repeated()) {
                    int count = ref->FieldSize(message, field);
                    for (int j = 0; j < count; j++) {
                        const google::protobuf::Message &innerMsg = ref->GetRepeatedMessage(message, field, j);
                        PrintProtoMsg(innerMsg);
                    }
                } else {
                    const google::protobuf::Message &innerMsg = ref->GetMessage(message, field);
                    PrintProtoMsg(innerMsg);
                }
            }
                break;
            default:
                break;
        }
    }
}


