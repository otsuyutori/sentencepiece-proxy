#include <stdio.h>
#include "sentencepiece_proxy.h"
#include "sentencepiece_processor.h"
sentencepiece::SentencePieceProcessor* SentencePieceProcessorCreate() {
    return new sentencepiece::SentencePieceProcessor();
}

sentencepiece::util::Status* SentencePieceProcessorLoad(sentencepiece::SentencePieceProcessor* pProcessor,char* path) { 
    return new sentencepiece::util::Status(pProcessor->Load(path));
}


sentencepiece::util::Status* SentencePieceProcessorEncode(sentencepiece::SentencePieceProcessor* pProcessor,char* text, int* len, int** ids) {
    std::vector<int> data;
    sentencepiece::util::Status status = pProcessor->Encode(text, &data);
    *len = data.size();
    *ids = new int[*len];
    for (int i = 0; i < *len; i++) {
        (*ids)[i] = data[i];
    }
    return new sentencepiece::util::Status(status);
}

bool SentencePieceProcessorStatusOk(sentencepiece::util::Status* pStatus) {
    return pStatus->ok();
}

void SentencePieceProcessorStatusMessage(sentencepiece::util::Status* pStatus, int* len, char* result) {
    auto msg = pStatus->ToString();
    *len = msg.size();
    strcpy(result, msg.c_str());
}

sentencepiece::util::Status* SentencePieceProcessorDecode(sentencepiece::SentencePieceProcessor* pProcessor, int len ,int* ids, char* result, int* result_len){
    std::vector<int> data;
    std::string detokenized;
    for (int i = 0; i < len; i++) {
        data.push_back(ids[i]);
    }
    sentencepiece::util::Status* status;
    status = new sentencepiece::util::Status(pProcessor->Decode(data, &detokenized));
    strcpy(result, detokenized.c_str());
    *result_len = detokenized.size();
    return status;
};

void SentencePieceProcessorDestroy(sentencepiece::SentencePieceProcessor* pProcessor) {
    delete pProcessor;
}

void SentencePieceProcessorStatusDestroy(sentencepiece::util::Status* pStatus) {
    delete pStatus;
}

sentencepiece::util::Status* SentencePieceProcessorSetEncodeExtraOptions(sentencepiece::SentencePieceProcessor* pProcessor,char* options) {
    return new sentencepiece::util::Status(pProcessor->SetEncodeExtraOptions(options));
}

sentencepiece::util::Status* SentencePieceProcessorSampleEncode(sentencepiece::SentencePieceProcessor* pProcessor,char* text, int nbest_size , float alpha,int* len, int* ids) {
    std::vector<int> data;
    sentencepiece::util::Status status = pProcessor->SampleEncode(text, nbest_size, alpha, &data);
    *len = data.size();
    for (int i = 0; i < *len; i++) {
        ids[i] = data[i];
    }
    return new sentencepiece::util::Status(status);
}

void SentencePieceProcessorDestroyIntArray(int* pArray) {
    delete[] pArray;
}

int SentencePieceProcessorGetPieceSize(sentencepiece::SentencePieceProcessor* pProcessor) {
    return pProcessor->GetPieceSize();
}