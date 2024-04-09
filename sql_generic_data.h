#ifndef SQL_GENERIC_DATA_H
#define SQL_GENERIC_DATA_H

#include "sqliteoperator.h"

#define id_logo_show                        21
#define id_sys_prompt_info                  25
#define id_sys_run_state                    31
#define id_sys_usb_state                    41
#define id_sys_sd_state                     42
#define id_sys_burn_state                   43
#define id_sys_wife_state                   44
#define id_sys_comm_state                   45
#define id_sys_abnormal_state               47

#define id_test_temperature_state           91
#define id_test_humidity_state              92
#define id_test_temperature_pv              101
#define id_test_temperature_sv              102
#define id_prec_temperature_pv              103
#define id_prec_temperature_sv              104
#define id_preh_temperature_pv              105
#define id_preh_temperature_sv              106
#define id_humidity_pv                      107
#define id_humidity_sv                      108
#define id_wet_temperature_pv               109
#define id_wet_temperature_sv               110


#define id_run_program_name                 121
#define id_program_run_time                 122
#define id_program_free_time                123
#define id_program_time                     124
#define id_segment_run_time                 125
#define id_segment_free_time                126
#define id_segment_time                     127
#define id_estimate_end_time                128
#define id_program_cycle                    129
#define id_program_run_segment              130
#define id_program_link                     131

#define id_test_temperature_heat_percent    141
#define id_humidity_heat_percent            142
#define id_server_percent                   143

#define id_high_temperature_protect         151
#define id_low_temperature_protect          152

#define id_ry_output1                       171
#define id_ry_output2                       172
#define id_ry_output3                       173
#define id_ry_output4                       174
#define id_ry_output5                       175
#define id_ry_output6                       176

#define id_run_pgm_step_row1                200
#define id_run_pgm_value1_row1              201
#define id_run_pgm_value2_row1              202
#define id_run_pgm_value3_row1              203
#define id_run_pgm_value4_row1              204
#define id_run_pgm_value5_row1              205
#define id_run_pgm_value6_row1              206
#define id_run_pgm_value7_row1              207
#define id_run_pgm_value8_row1              208
#define id_run_pgm_value9_row1              209
#define id_run_pgm_hour_row1                210
#define id_run_pgm_min_row1                 211
#define id_run_pgm_sec_row1                 212
#define id_run_pgm_ts1_row1                 213
#define id_run_pgm_ts2_row1                 214
#define id_run_pgm_ts3_row1                 215
#define id_run_pgm_ts4_row1                 216
#define id_run_pgm_ts5_row1                 217
#define id_run_pgm_ts6_row1                 218
#define id_run_pgm_wt_row1                  219
#define id_run_pgm_rain_row1                220
#define id_run_pgm_roll_row1                221


#define id_run_pgm_step_row2                225
#define id_run_pgm_value1_row2              226
#define id_run_pgm_value2_row2              227
#define id_run_pgm_value3_row2              228
#define id_run_pgm_value4_row2              229
#define id_run_pgm_value5_row2              230
#define id_run_pgm_value6_row2              231
#define id_run_pgm_value7_row2              232
#define id_run_pgm_value8_row2              233
#define id_run_pgm_value9_row2              234
#define id_run_pgm_hour_row2                235
#define id_run_pgm_min_row2                 236
#define id_run_pgm_sec_row2                 237
#define id_run_pgm_ts1_row2                 238
#define id_run_pgm_ts2_row2                 239
#define id_run_pgm_ts3_row2                 240
#define id_run_pgm_ts4_row2                 241
#define id_run_pgm_ts5_row2                 242
#define id_run_pgm_ts6_row2                 243
#define id_run_pgm_wt_row2                  244
#define id_run_pgm_rain_row2                245
#define id_run_pgm_roll_row2                246

#define id_run_pgm_step_row3                250
#define id_run_pgm_value1_row3              251
#define id_run_pgm_value2_row3              252
#define id_run_pgm_value3_row3              253
#define id_run_pgm_value4_row3              254
#define id_run_pgm_value5_row3              255
#define id_run_pgm_value6_row3              256
#define id_run_pgm_value7_row3              257
#define id_run_pgm_value8_row3              258
#define id_run_pgm_value9_row3              259
#define id_run_pgm_hour_row3                260
#define id_run_pgm_min_row3                 261
#define id_run_pgm_sec_row3                 262
#define id_run_pgm_ts1_row3                 263
#define id_run_pgm_ts2_row3                 264
#define id_run_pgm_ts3_row3                 265
#define id_run_pgm_ts4_row3                 266
#define id_run_pgm_ts5_row3                 267
#define id_run_pgm_ts6_row3                 268
#define id_run_pgm_wt_row3                  269
#define id_run_pgm_rain_row3                270
#define id_run_pgm_roll_row3                271

#define id_run_pgm_step_row4                275
#define id_run_pgm_value1_row4              276
#define id_run_pgm_value2_row4              277
#define id_run_pgm_value3_row4              278
#define id_run_pgm_value4_row4              279
#define id_run_pgm_value5_row4              280
#define id_run_pgm_value6_row4              281
#define id_run_pgm_value7_row4              282
#define id_run_pgm_value8_row4              283
#define id_run_pgm_value9_row4              284
#define id_run_pgm_hour_row4                285
#define id_run_pgm_min_row4                 286
#define id_run_pgm_sec_row4                 287
#define id_run_pgm_ts1_row4                 288
#define id_run_pgm_ts2_row4                 289
#define id_run_pgm_ts3_row4                 290
#define id_run_pgm_ts4_row4                 291
#define id_run_pgm_ts5_row4                 292
#define id_run_pgm_ts6_row4                 293
#define id_run_pgm_wt_row4                  294
#define id_run_pgm_rain_row4                295
#define id_run_pgm_roll_row4                296



#define addr_logo_show                        0x00
#define addr_sys_prompt_info                  0xE0
#define addr_sys_run_state                    0xA1
#define addr_sys_usb_state                    0x79
#define addr_sys_sd_state                     0x78
#define addr_sys_burn_state                   0x7A
#define addr_sys_wife_state                   0x7B
#define addr_sys_comm_state                   0x7C
#define addr_sys_abnormal_state               0x7D

#define addr_test_temperature_state           0x1A0
#define addr_test_humidity_state              0x1A3
#define addr_test_temperature_pv              0x101
#define addr_test_temperature_sv              0x103
#define addr_prec_temperature_pv              0x00
#define addr_prec_temperature_sv              0x00
#define addr_preh_temperature_pv              0x00
#define addr_preh_temperature_sv              0x00
#define addr_humidity_pv                      0x10B
#define addr_humidity_sv                      0x105
#define addr_wet_temperature_pv               0x00
#define addr_wet_temperature_sv               0x00

#define addr_run_program_name                 0x110
#define addr_program_run_time                 0x170
#define addr_program_free_time                0x180
#define addr_program_time                     0x170
#define addr_segment_run_time                 0x150
#define addr_segment_free_time                0x160
#define addr_segment_time                     0x150
#define addr_estimate_end_time                0x190
#define addr_program_cycle                    0x130
#define addr_program_run_segment              0x127
#define addr_program_link                     0x140

#define addr_test_temperature_heat_percent    0x263
#define addr_humidity_heat_percent            0x264
#define addr_server_percent                   0x265

#define addr_high_temperature_protect         0x261
#define addr_low_temperature_protect          0x262

#define addr_ry_output1                       0x2A0
#define addr_ry_output2                       0x2B0
#define addr_ry_output3                       0x2C0
#define addr_ry_output4                       0x2D0
#define addr_ry_output5                       0x2E0
#define addr_ry_output6                       0x2F0

#define addr_run_pgm_step_row1                0x220
#define addr_run_pgm_value1_row1              0x221
#define addr_run_pgm_value2_row1              0x222
#define addr_run_pgm_value3_row1              0x0
#define addr_run_pgm_value4_row1              0x0
#define addr_run_pgm_value5_row1              0x0
#define addr_run_pgm_value6_row1              0x0
#define addr_run_pgm_value7_row1              0x0
#define addr_run_pgm_value8_row1              0x0
#define addr_run_pgm_value9_row1              0x0
#define addr_run_pgm_hour_row1                0x223
#define addr_run_pgm_min_row1                 0x224
#define addr_run_pgm_sec_row1                 0x225
#define addr_run_pgm_ts1_row1                 0x226
#define addr_run_pgm_ts2_row1                 0x227
#define addr_run_pgm_ts3_row1                 0x228
#define addr_run_pgm_ts4_row1                 0x0
#define addr_run_pgm_ts5_row1                 0x0
#define addr_run_pgm_ts6_row1                 0x0
#define addr_run_pgm_wt_row1                  0x229
#define addr_run_pgm_rain_row1                0x0
#define addr_run_pgm_roll_row1                0x0


#define addr_run_pgm_step_row2                0x230
#define addr_run_pgm_value1_row2              0x231
#define addr_run_pgm_value2_row2              0x232
#define addr_run_pgm_value3_row2              0x0
#define addr_run_pgm_value4_row2              0x0
#define addr_run_pgm_value5_row2              0x0
#define addr_run_pgm_value6_row2              0x0
#define addr_run_pgm_value7_row2              0x0
#define addr_run_pgm_value8_row2              0x0
#define addr_run_pgm_value9_row2              0x0
#define addr_run_pgm_hour_row2                0x233
#define addr_run_pgm_min_row2                 0x234
#define addr_run_pgm_sec_row2                 0x235
#define addr_run_pgm_ts1_row2                 0x236
#define addr_run_pgm_ts2_row2                 0x237
#define addr_run_pgm_ts3_row2                 0x238
#define addr_run_pgm_ts4_row2                 0x0
#define addr_run_pgm_ts5_row2                 0x0
#define addr_run_pgm_ts6_row2                 0x0
#define addr_run_pgm_wt_row2                  0x239
#define addr_run_pgm_rain_row2                0x0
#define addr_run_pgm_roll_row2                0x0

#define addr_run_pgm_step_row3                0x240
#define addr_run_pgm_value1_row3              0x241
#define addr_run_pgm_value2_row3              0x242
#define addr_run_pgm_value3_row3              0x0
#define addr_run_pgm_value4_row3              0x0
#define addr_run_pgm_value5_row3              0x0
#define addr_run_pgm_value6_row3              0x0
#define addr_run_pgm_value7_row3              0x0
#define addr_run_pgm_value8_row3              0x0
#define addr_run_pgm_value9_row3              0x0
#define addr_run_pgm_hour_row3                0x243
#define addr_run_pgm_min_row3                 0x244
#define addr_run_pgm_sec_row3                 0x245
#define addr_run_pgm_ts1_row3                 0x246
#define addr_run_pgm_ts2_row3                 0x247
#define addr_run_pgm_ts3_row3                 0x248
#define addr_run_pgm_ts4_row3                 0x0
#define addr_run_pgm_ts5_row3                 0x0
#define addr_run_pgm_ts6_row3                 0x0
#define addr_run_pgm_wt_row3                  0x249
#define addr_run_pgm_rain_row3                0x0
#define addr_run_pgm_roll_row3                0x0

#define addr_run_pgm_step_row4                0x250
#define addr_run_pgm_value1_row4              0x251
#define addr_run_pgm_value2_row4              0x252
#define addr_run_pgm_value3_row4              0x0
#define addr_run_pgm_value4_row4              0x0
#define addr_run_pgm_value5_row4              0x0
#define addr_run_pgm_value6_row4              0x0
#define addr_run_pgm_value7_row4              0x0
#define addr_run_pgm_value8_row4              0x0
#define addr_run_pgm_value9_row4              0x0
#define addr_run_pgm_hour_row4                0x253
#define addr_run_pgm_min_row4                 0x254
#define addr_run_pgm_sec_row4                 0x255
#define addr_run_pgm_ts1_row4                 0x256
#define addr_run_pgm_ts2_row4                 0x257
#define addr_run_pgm_ts3_row4                 0x258
#define addr_run_pgm_ts4_row4                 0x0
#define addr_run_pgm_ts5_row4                 0x0
#define addr_run_pgm_ts6_row4                 0x0
#define addr_run_pgm_wt_row4                  0x259
#define addr_run_pgm_rain_row4                0x0
#define addr_run_pgm_roll_row4                0x0








void readDBData(void);
void readComDBData(QVector<lcd_show_data_f>& lcd_vector);
void writeTouchDBData(int id, int page ,int addr,int data, QString str, int swi, QString font, int size, QString color, QString position, QString other);

#endif // SQL_GENERIC_DATA_H
