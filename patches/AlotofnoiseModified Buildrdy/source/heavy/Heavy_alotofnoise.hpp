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

#ifndef _HEAVY_CONTEXT_ALOTOFNOISE_HPP_
#define _HEAVY_CONTEXT_ALOTOFNOISE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlIf.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlCast.h"

class Heavy_alotofnoise : public HeavyContext {

 public:
  Heavy_alotofnoise(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_alotofnoise();

  const char *getName() override { return "alotofnoise"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_83zJESL0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_NSpBlV23_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0xtmHgkB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NyAW0hVE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0NmltOlL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_84j82UYr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Ocs1Vhz5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8pwFrvcq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bXSc9i7a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kzf2SwLS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8h92ebC8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_c0FMetWf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dAQOddYU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Z0sUxpyi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TV9VFjet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_nvX9cPkO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rwDaqQWn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_v2yesYpY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d8eBppHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WN3ObafE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PdfjUQW5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_S0ALFEKm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dRd6Zejr_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_QLv2ww7u;
  SignalPhasor sPhasor_iLni2oQJ;
  SignalPhasor sPhasor_l0NpH4Jw;
  SignalVarf sVarf_fp8FtfMt;
  ControlVar cVar_83zJESL0;
  ControlVar cVar_0xtmHgkB;
  ControlVar cVar_NyAW0hVE;
  SignalVarf sVarf_E8FgakP4;
  ControlVar cVar_8pwFrvcq;
  ControlVar cVar_kzf2SwLS;
  ControlVar cVar_8h92ebC8;
  ControlVar cVar_c0FMetWf;
  ControlVar cVar_dAQOddYU;
  ControlBinop cBinop_TV9VFjet;
  ControlIf cIf_nvX9cPkO;
  ControlBinop cBinop_rwDaqQWn;
  ControlBinop cBinop_WN3ObafE;
  ControlBinop cBinop_PdfjUQW5;
  ControlBinop cBinop_dRd6Zejr;
};

#endif // _HEAVY_CONTEXT_ALOTOFNOISE_HPP_
