#include "sentencepiece_processor.h"
#ifndef TEST_H
#define TEST_H
#endif
#ifdef __cplusplus
extern "C" {
#endif
    sentencepiece::SentencePieceProcessor* SentencePieceProcessorCreate();
    sentencepiece::util::Status* SentencePieceProcessorLoad(sentencepiece::SentencePieceProcessor* ,char*);
    sentencepiece::util::Status* SentencePieceProcessorEncode(sentencepiece::SentencePieceProcessor* ,char* , int* , int** );
    bool SentencePieceProcessorStatusOk(sentencepiece::util::Status*);
    sentencepiece::util::Status* SentencePieceProcessorDecode(sentencepiece::SentencePieceProcessor* , int ,int* , char* );
    void SentencePieceProcessorDestroy(sentencepiece::SentencePieceProcessor* );
    void SentencePieceProcessorStatusDestroy(sentencepiece::util::Status* );
    sentencepiece::util::Status* SentencePieceProcessorSetEncodeExtraOptions(sentencepiece::SentencePieceProcessor* ,char* );
    sentencepiece::util::Status* SentencePieceProcessorSampleEncode(sentencepiece::SentencePieceProcessor* ,char* , int , float ,int* , int* );
    void SentencePieceProcessorStatusMessage(sentencepiece::util::Status* , int*, char*);
    void SentencePieceProcessorDestroyIntArray(int*);
    int SentencePieceProcessorGetPieceSize(sentencepiece::SentencePieceProcessor*);
#ifdef __cplusplus
}
#endif