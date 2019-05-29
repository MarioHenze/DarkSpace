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

#ifndef _HEAVY_CONTEXT_PIEPTON_HPP_
#define _HEAVY_CONTEXT_PIEPTON_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlPack.h"
#include "HvControlCast.h"

class Heavy_piepton : public HeavyContext {

 public:
  Heavy_piepton(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_piepton();

  const char *getName() override { return "piepton"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        DECAYTIME = 0x7A9CE2DE, // decayTime
        METRO = 0x9E78BC0, // metro
        SOUNDBAR = 0xB80E41DD, // soundBar
        TONONE = 0xA1C1B8D3, // tonOne
        TONTWO = 0x5AF3704F, // tonTwo
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cReceive_kEvFDoEt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5tyoLKaB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3ZvXcmLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y1C8ifLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AUL1XeGs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6FZIcsdw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mgo76oCT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Vc8Xltbl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3pE6L8Ir_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_3cLfwtn6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zhP0dpES_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_7FUC55gk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_90UjjRSN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_JnhiVYYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cjqkvxDV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_aOmAy0uw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sJl56vAX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ZFK78MXz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_J79HwZvZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QzEKqwai_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KZ8lruns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SuEPgYfQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f6LZD5mo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_h1gpsqfD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ShPKBBKq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_1fwhkam1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jKeuDS75_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Rm0lnJUC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yQ3etf04_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ye18i1je_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JM9hxXE0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_3kOtBLEp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YdnkWXql_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TvRfmzFa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_r8dkUxGO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_R016rST4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_bFVlFZVl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_gKw86Sv1_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_03EEcbAk;
  SignalPhasor sPhasor_uD3nqlzy;
  ControlVar cVar_5tyoLKaB;
  ControlBinop cBinop_3ZvXcmLH;
  ControlVar cVar_y1C8ifLH;
  ControlBinop cBinop_AUL1XeGs;
  ControlVar cVar_mgo76oCT;
  ControlVar cVar_Vc8Xltbl;
  SignalVarf sVarf_NcqSTAOb;
  ControlDelay cDelay_JnhiVYYl;
  ControlVar cVar_sJl56vAX;
  SignalVarf sVarf_uNhQBKQo;
  ControlVar cVar_J79HwZvZ;
  ControlVar cVar_QzEKqwai;
  ControlVar cVar_KZ8lruns;
  ControlVar cVar_SuEPgYfQ;
  ControlVar cVar_1fwhkam1;
  ControlBinop cBinop_jKeuDS75;
  ControlBinop cBinop_yQ3etf04;
  ControlBinop cBinop_Ye18i1je;
  ControlVar cVar_YdnkWXql;
  ControlDelay cDelay_R016rST4;
  ControlPack cPack_bFVlFZVl;
};

#endif // _HEAVY_CONTEXT_PIEPTON_HPP_
