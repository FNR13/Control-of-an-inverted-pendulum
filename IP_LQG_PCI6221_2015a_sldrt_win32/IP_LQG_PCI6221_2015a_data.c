/*
 * IP_LQG_PCI6221_2015a_data.c
 *
 * Code generation for model "IP_LQG_PCI6221_2015a".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 17 12:37:41 2025
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IP_LQG_PCI6221_2015a.h"
#include "IP_LQG_PCI6221_2015a_private.h"

/* Block parameters (auto storage) */
P_IP_LQG_PCI6221_2015a_T IP_LQG_PCI6221_2015a_P = {
  /*  Variable: A
   * Referenced by: '<Root>/LQG'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -0.017404859575843416, 0.0,
    -0.017375920561817897, -232.02520137511431, 0.0, 20.786124708700459, 0.0,
    63.831866309774568, 0.0, 0.0, -0.0023164464704312983, 1.0,
    -0.0071135482677263393, 0.0, 0.0, 57.534432075073113, 0.0,
    57.438769726892971, -755.4249991873927 },
  1.5707963267948966,                  /* Variable: ALPHA_MAX
                                        * Referenced by:
                                        *   '<S5>/Lower Limit'
                                        *   '<S5>/Upper Limit'
                                        */
  0.26179938779914941,                 /* Variable: BETA_MAX
                                        * Referenced by:
                                        *   '<S3>/Lower Limit'
                                        *   '<S3>/Upper Limit'
                                        */

  /*  Variable: K
   * Referenced by: '<Root>/LQG'
   */
  { -44.721359548432304, -29.961625525575517, 320.31636978244921,
    50.1504455881371, 1.2088532183818876 },

  /*  Variable: L
   * Referenced by: '<Root>/LQG'
   */
  { 3.2666498192740487, 0.98199285424382743, 1.1370948362933486,
    8.0783837026804015, -0.29903792291344472, 1.1370948362933486,
    11.872529714783305, 14.278864222894381, 97.589474081295265,
    -3.6109237059447508 },
  6.0,                                 /* Variable: TIME_DELAY
                                        * Referenced by: '<S1>/Time delay'
                                        */
  5.0,                                 /* Variable: V_MAX
                                        * Referenced by: '<S1>/Motor protection'
                                        */
  -5.0,                                /* Variable: V_MIN
                                        * Referenced by: '<S1>/Motor protection'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_FinalValue
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_InitialValue
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_InputFilter
                                        * Referenced by: '<S4>/Encoder Input1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_InputFilter
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_MaxMissedTicks
                                        * Referenced by: '<S4>/Encoder Input1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_MaxMissedTicks
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  10.0,                                /* Mask Parameter: AnalogOutput_MaxMissedTicks
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput1_YieldWhenWaiting
                                        * Referenced by: '<S4>/Encoder Input1'
                                        */
  0.0,                                 /* Mask Parameter: EncoderInput_YieldWhenWaiting
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  0.0,                                 /* Mask Parameter: AnalogOutput_YieldWhenWaiting
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: EncoderInput1_Channels
                                        * Referenced by: '<S4>/Encoder Input1'
                                        */
  1,                                   /* Mask Parameter: EncoderInput_Channels
                                        * Referenced by: '<S6>/Encoder Input'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_Channels
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_RangeMode
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0,                                   /* Mask Parameter: AnalogOutput_VoltRange
                                        * Referenced by: '<S1>/Analog Output'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/LQG'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S7>/Angle'
                                        */
  4096.0,                              /* Expression: 4096
                                        * Referenced by: '<S7>/Encoder resolution'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S6>/Angle'
                                        */
  4096.0,                              /* Expression: 4096
                                        * Referenced by: '<S6>/Encoder resolution'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Bias'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Time delay'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Time delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Const motor'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S1>/Motor switch'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S1>/Const sensors'
   */
  { 0.0, 0.0 },
  3.0                                  /* Expression: 3
                                        * Referenced by: '<S1>/Sensors switch'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_IP_LQG_PCI6221_2015a_T IP_LQG_PCI6221_2015a_ConstP = {
  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/LQG'
   */
  { 0.0, 0.0, 0.0, 0.0, -14907.272563812785, 0.0, 0.0, 0.0, 0.0,
    -9987.3108213746546, 0.0, 0.0, 0.0, 0.0, 106773.21707598676, 0.0, 0.0, 0.0,
    0.0, 16716.986449604243, 0.0, 0.0, 0.0, 0.0, 402.95520078152026 },

  /* Expression: A-B*K-L*C
   * Referenced by: '<Root>/LQG'
   */
  { 3.2666498192740487, 0.98199285424382743, 1.1370948362933486,
    8.0783837026804015, -0.29903792291344472, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.1370948362933486, 11.872529714783305, 14.278864222894381,
    97.589474081295265, -3.6109237059447508, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 }
};
