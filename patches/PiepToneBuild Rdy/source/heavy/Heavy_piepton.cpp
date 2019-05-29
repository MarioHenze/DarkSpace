/**
 * Copyright (c) 2019 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_piepton.hpp"

#define Context(_c) reinterpret_cast<Heavy_piepton *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_piepton_new(double sampleRate) {
    return new Heavy_piepton(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_piepton_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_piepton(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_piepton::Heavy_piepton(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_03EEcbAk);
  numBytes += sPhasor_init(&sPhasor_uD3nqlzy, sampleRate);
  numBytes += cVar_init_f(&cVar_5tyoLKaB, 1.0f);
  numBytes += cVar_init_f(&cVar_y1C8ifLH, 1.0f);
  numBytes += cVar_init_f(&cVar_mgo76oCT, 0.0f);
  numBytes += cVar_init_f(&cVar_Vc8Xltbl, 0.0f);
  numBytes += sVarf_init(&sVarf_NcqSTAOb, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_JnhiVYYl, 500.0f);
  numBytes += cVar_init_f(&cVar_sJl56vAX, 0.0f);
  numBytes += sVarf_init(&sVarf_uNhQBKQo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_J79HwZvZ, 0.0f);
  numBytes += cVar_init_f(&cVar_QzEKqwai, 0.0f);
  numBytes += cVar_init_f(&cVar_KZ8lruns, 0.0f);
  numBytes += cVar_init_f(&cVar_SuEPgYfQ, 0.0f);
  numBytes += cVar_init_f(&cVar_1fwhkam1, 0.0f);
  numBytes += cBinop_init(&cBinop_Ye18i1je, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YdnkWXql, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_R016rST4, 0.0f);
  numBytes += cPack_init(&cPack_bFVlFZVl, 2, 0.0f, 500.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_piepton::~Heavy_piepton() {
  cPack_free(&cPack_bFVlFZVl);
}

HvTable *Heavy_piepton::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_piepton::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zhP0dpES_sendMessage);
      break;
    }
    case 0x7A9CE2DE: { // decayTime
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3cLfwtn6_sendMessage);
      break;
    }
    case 0x9E78BC0: { // metro
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aOmAy0uw_sendMessage);
      break;
    }
    case 0xB80E41DD: { // soundBar
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ZFK78MXz_sendMessage);
      break;
    }
    case 0xA1C1B8D3: { // tonOne
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kEvFDoEt_sendMessage);
      break;
    }
    case 0x5AF3704F: { // tonTwo
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gKw86Sv1_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_piepton::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "soundBar";
        info->hash = 0xB80E41DD;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 10.0f;
        info->defaultVal = 1.0f;
        break;
      }
      case 1: {
        info->name = "tonOne";
        info->hash = 0xA1C1B8D3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 1.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 50.0f;
        break;
      }
      case 2: {
        info->name = "decayTime";
        info->hash = 0x7A9CE2DE;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 1.0f;
        break;
      }
      case 3: {
        info->name = "tonTwo";
        info->hash = 0x5AF3704F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 1.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 40.0f;
        break;
      }
      case 4: {
        info->name = "metro";
        info->hash = 0x9E78BC0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 1.0f;
        info->maxVal = 100000.0f;
        info->defaultVal = 500.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 5;
}



/*
 * Send Function Implementations
 */


void Heavy_piepton::cReceive_kEvFDoEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KZ8lruns, 0, m, &cVar_KZ8lruns_sendMessage);
}

void Heavy_piepton::cVar_5tyoLKaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_3ZvXcmLH_sendMessage);
  cSwitchcase_ShPKBBKq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_piepton::cBinop_3ZvXcmLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5tyoLKaB, 1, m, &cVar_5tyoLKaB_sendMessage);
}

void Heavy_piepton::cVar_y1C8ifLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_AUL1XeGs_sendMessage);
  cSwitchcase_JM9hxXE0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_piepton::cBinop_AUL1XeGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y1C8ifLH, 1, m, &cVar_y1C8ifLH_sendMessage);
}

void Heavy_piepton::cCast_6FZIcsdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3pE6L8Ir_sendMessage(_c, 0, m);
  cSwitchcase_7FUC55gk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_piepton::cVar_mgo76oCT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sJl56vAX, 0, m, &cVar_sJl56vAX_sendMessage);
}

void Heavy_piepton::cVar_Vc8Xltbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NcqSTAOb, m);
}

void Heavy_piepton::cMsg_3pE6L8Ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 50.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_03EEcbAk, 0, m, NULL);
}

void Heavy_piepton::cReceive_3cLfwtn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1fwhkam1, 0, m, &cVar_1fwhkam1_sendMessage);
}

void Heavy_piepton::cReceive_zhP0dpES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TvRfmzFa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YdnkWXql, 0, m, &cVar_YdnkWXql_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y1C8ifLH, 0, m, &cVar_y1C8ifLH_sendMessage);
}

void Heavy_piepton::cSwitchcase_7FUC55gk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_cjqkvxDV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_cjqkvxDV_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_JnhiVYYl, 1, m, &cDelay_JnhiVYYl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_90UjjRSN_sendMessage);
      break;
    }
  }
}

void Heavy_piepton::cCast_90UjjRSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JnhiVYYl, 0, m, &cDelay_JnhiVYYl_sendMessage);
}

void Heavy_piepton::cDelay_JnhiVYYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JnhiVYYl, m);
  cPack_onMessage(_c, &Context(_c)->cPack_bFVlFZVl, 0, m, &cPack_bFVlFZVl_sendMessage);
}

void Heavy_piepton::cMsg_cjqkvxDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JnhiVYYl, 0, m, &cDelay_JnhiVYYl_sendMessage);
}

void Heavy_piepton::cReceive_aOmAy0uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SuEPgYfQ, 0, m, &cVar_SuEPgYfQ_sendMessage);
}

void Heavy_piepton::cVar_sJl56vAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vc8Xltbl, 0, m, &cVar_Vc8Xltbl_sendMessage);
}

void Heavy_piepton::cReceive_ZFK78MXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J79HwZvZ, 0, m, &cVar_J79HwZvZ_sendMessage);
}

void Heavy_piepton::cVar_J79HwZvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uNhQBKQo, m);
}

void Heavy_piepton::cVar_QzEKqwai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vc8Xltbl, 0, m, &cVar_Vc8Xltbl_sendMessage);
}

void Heavy_piepton::cVar_KZ8lruns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QzEKqwai, 0, m, &cVar_QzEKqwai_sendMessage);
}

void Heavy_piepton::cVar_SuEPgYfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YdnkWXql, 0, m, &cVar_YdnkWXql_sendMessage);
}

void Heavy_piepton::cCast_f6LZD5mo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sJl56vAX, 0, m, &cVar_sJl56vAX_sendMessage);
}

void Heavy_piepton::cCast_h1gpsqfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QzEKqwai, 0, m, &cVar_QzEKqwai_sendMessage);
}

void Heavy_piepton::cSwitchcase_ShPKBBKq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h1gpsqfD_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f6LZD5mo_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_piepton::cVar_1fwhkam1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bFVlFZVl, 1, m, &cPack_bFVlFZVl_sendMessage);
}

void Heavy_piepton::cBinop_jKeuDS75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ye18i1je, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ye18i1je_sendMessage);
}

void Heavy_piepton::cCast_Rm0lnJUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3kOtBLEp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_R016rST4, 0, m, &cDelay_R016rST4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5tyoLKaB, 0, m, &cVar_5tyoLKaB_sendMessage);
}

void Heavy_piepton::cBinop_yQ3etf04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_R016rST4, 2, m, &cDelay_R016rST4_sendMessage);
}

void Heavy_piepton::cBinop_Ye18i1je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yQ3etf04_sendMessage);
}

void Heavy_piepton::cSwitchcase_JM9hxXE0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_3kOtBLEp_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_3kOtBLEp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Rm0lnJUC_sendMessage);
      break;
    }
  }
}

void Heavy_piepton::cMsg_3kOtBLEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_R016rST4, 0, m, &cDelay_R016rST4_sendMessage);
}

void Heavy_piepton::cVar_YdnkWXql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ye18i1je, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ye18i1je_sendMessage);
}

void Heavy_piepton::cMsg_TvRfmzFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r8dkUxGO_sendMessage);
}

void Heavy_piepton::cSystem_r8dkUxGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jKeuDS75_sendMessage);
}

void Heavy_piepton::cDelay_R016rST4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_R016rST4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_R016rST4, 0, m, &cDelay_R016rST4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5tyoLKaB, 0, m, &cVar_5tyoLKaB_sendMessage);
}

void Heavy_piepton::cPack_bFVlFZVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_03EEcbAk, 0, m, NULL);
}

void Heavy_piepton::cReceive_gKw86Sv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mgo76oCT, 0, m, &cVar_mgo76oCT_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_piepton::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_line_f(&sLine_03EEcbAk, VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_NcqSTAOb, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.0577622650467f, 0.0577622650467f, 0.0577622650467f, 0.0577622650467f, 0.0577622650467f, 0.0577622650467f, 0.0577622650467f, 0.0577622650467f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_exp_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 8.17579891564f, 8.17579891564f, 8.17579891564f, 8.17579891564f, 8.17579891564f, 8.17579891564f, 8.17579891564f, 8.17579891564f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_uD3nqlzy, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_uNhQBKQo, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_piepton::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_piepton::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
