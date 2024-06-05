#ifndef ADDRESS_DATA_SHOW_H
#define ADDRESS_DATA_SHOW_H



#define addr_touch_pageturn_pbtn           0x10
#define addr_run_popup_ok_pbtn              0x11
#define addr_logo_show                        0x00
#define addr_touch_run_pbtn                   0x20
#define addr_touch_load_pbtn                  0x60
#define addr_touch_onepoint_pbtn              0x6A
#define addr_touch_reset_pbtn                 0xA0
#define addr_touch_pause_pbtn               0x6B
#define addr_touch_lamp_pbtn                0xA0
#define addr_touch_monitor_nextpage_pbtn    0x1B0

#define addr_sys_prompt_info                0xE0
#define addr_run_stop_pbtn_state            0x75
#define addr_run_flag_state                0xA1
#define addr_light_pbtn_state               0xA3
#define addr_sys_usb_state                  0x79
#define addr_sys_sd_state                   0x78
#define addr_sys_burn_state                 0x7A
#define addr_sys_wifi_state                 0x7B
#define addr_sys_comm_state                 0x7C
#define addr_sys_abnormal_state             0x7D


#define addr_test_temperature_pv              0x101
#define addr_touch_test_temperature_sv        0x102
#define addr_test_temperature_sv              0x103
#define addr_prec_temperature_pv              0x00
#define addr_prec_temperature_sv              0x00
#define addr_preh_temperature_pv              0x00
#define addr_preh_temperature_sv              0x00
#define addr_humidity_pv                      0x10B
#define addr_humidity_sv                      0x105
#define addr_touch_humidity_sv                0x106
#define addr_wet_temperature_pv               0x00
#define addr_wet_temperature_sv               0x00

#define addr_run_program_name                 0x110
#define addr_program_run_time                 0x170
#define addr_program_free_time                0x180
#define addr_segment_run_time                 0x150
#define addr_segment_free_time                0x160
#define addr_estimate_end_time                0x190
#define addr_program_cycle                    0x130
#define addr_program_run_segment              0x127
#define addr_program_link                     0x140
#define addr_test_temperature_state           0x1A0
#define addr_test_humidity_state              0x1A3
#define addr_test_temperature_heat_percent    0x263
#define addr_humidity_heat_percent            0x264
#define addr_server_percent                   0x265

#define addr_high_temperature_protect         0x261
#define addr_low_temperature_protect          0x262
#define addr_rapid_percent                    0x266

#define addr_ry_output1                       0x2A0
#define addr_ry_output2                       0x2B0
#define addr_ry_output3                       0x2C0
#define addr_ry_output4                       0x2D0
#define addr_ry_output5                       0x2E0
#define addr_ry_output6                       0x2F0

#define addr_touch_run_pgm_edit               0x200
#define addr_touch_run_pgm_jump               0x201
#define addr_run_pgm_step_row1                0x220
#define addr_run_pgm_value1_row1              0x221
#define addr_run_pgm_value2_row1              0x222
#define addr_run_pgm_hour_row1                0x223
#define addr_run_pgm_min_row1                 0x224
#define addr_run_pgm_sec_row1                 0x225
#define addr_run_pgm_ts1_row1                 0x226
#define addr_run_pgm_ts2_row1                 0x227
#define addr_run_pgm_ts3_row1                 0x228
#define addr_run_pgm_wt_row1                  0x229
#define addr_run_pgm_step_row2                0x230
#define addr_run_pgm_value1_row2              0x231
#define addr_run_pgm_value2_row2              0x232
#define addr_run_pgm_hour_row2                0x233
#define addr_run_pgm_min_row2                 0x234
#define addr_run_pgm_sec_row2                 0x235
#define addr_run_pgm_ts1_row2                 0x236
#define addr_run_pgm_ts2_row2                 0x237
#define addr_run_pgm_ts3_row2                 0x238
#define addr_run_pgm_wt_row2                  0x239


#define addr_run_pgm_step_row3                0x240
#define addr_run_pgm_value1_row3              0x241
#define addr_run_pgm_value2_row3              0x242
#define addr_run_pgm_hour_row3                0x243
#define addr_run_pgm_min_row3                 0x244
#define addr_run_pgm_sec_row3                 0x245
#define addr_run_pgm_ts1_row3                 0x246
#define addr_run_pgm_ts2_row3                 0x247
#define addr_run_pgm_ts3_row3                 0x248
#define addr_run_pgm_wt_row3                  0x249


#define addr_run_pgm_step_row4                0x250
#define addr_run_pgm_value1_row4              0x251
#define addr_run_pgm_value2_row4              0x252
#define addr_run_pgm_hour_row4                0x253
#define addr_run_pgm_min_row4                 0x254
#define addr_run_pgm_sec_row4                 0x255
#define addr_run_pgm_ts1_row4                 0x256
#define addr_run_pgm_ts2_row4                 0x257
#define addr_run_pgm_ts3_row4                 0x258
#define addr_run_pgm_wt_row4                  0x259

#define addr_pgm_edit_pgm_name                  0x400
#define addr_touch_pgm_edit_pgm_name            0x400
#define addr_pgm_edit_pgm_number                0x410
#define addr_touch_pgm_edit_pgm_number          0x411
#define addr_pgm_edit_hilimit                  0x425
#define addr_pgm_edit_lolimit                  0x424

#define addr_edit_pgm_step_row1                0x440
#define addr_edit_pgm_value1_row1              0x441
#define addr_edit_pgm_value2_row1              0x442
#define addr_edit_pgm_hour_row1                0x443
#define addr_edit_pgm_min_row1                 0x444
#define addr_edit_pgm_sec_row1                 0x445
#define addr_edit_pgm_ts1_row1                 0x446
#define addr_edit_pgm_ts2_row1                 0x447
#define addr_edit_pgm_ts3_row1                 0x448
#define addr_edit_pgm_wt_row1                  0x449

#define addr_touch_edit_pgm_value1_row1              0x451
#define addr_touch_edit_pgm_value2_row1              0x452
#define addr_touch_edit_pgm_hour_row1                0x453
#define addr_touch_edit_pgm_min_row1                 0x454
#define addr_touch_edit_pgm_sec_row1                 0x455
#define addr_touch_edit_pgm_ts1_row1                 0x456
#define addr_touch_edit_pgm_ts2_row1                 0x457
#define addr_touch_edit_pgm_ts3_row1                 0x458
#define addr_touch_edit_pgm_wt_row1                  0x459

#define addr_edit_pgm_step_row2                0x460
#define addr_edit_pgm_value1_row2              0x461
#define addr_edit_pgm_value2_row2              0x462
#define addr_edit_pgm_hour_row2                0x463
#define addr_edit_pgm_min_row2                 0x464
#define addr_edit_pgm_sec_row2                 0x465
#define addr_edit_pgm_ts1_row2                 0x466
#define addr_edit_pgm_ts2_row2                 0x467
#define addr_edit_pgm_ts3_row2                 0x468
#define addr_edit_pgm_wt_row2                  0x469

#define addr_touch_edit_pgm_value1_row2             0x471
#define addr_touch_edit_pgm_value2_row2             0x472
#define addr_touch_edit_pgm_hour_row2               0x473
#define addr_touch_edit_pgm_min_row2                0x474
#define addr_touch_edit_pgm_sec_row2                0x475
#define addr_touch_edit_pgm_ts1_row2                0x476
#define addr_touch_edit_pgm_ts2_row2                0x477
#define addr_touch_edit_pgm_ts3_row2                0x478
#define addr_touch_edit_pgm_wt_row2                 0x479

#define addr_edit_pgm_step_row3                0x480
#define addr_edit_pgm_value1_row3              0x481
#define addr_edit_pgm_value2_row3              0x482
#define addr_edit_pgm_hour_row3                0x483
#define addr_edit_pgm_min_row3                 0x484
#define addr_edit_pgm_sec_row3                 0x485
#define addr_edit_pgm_ts1_row3                 0x486
#define addr_edit_pgm_ts2_row3                 0x487
#define addr_edit_pgm_ts3_row3                 0x488
#define addr_edit_pgm_wt_row3                  0x489

#define addr_touch_edit_pgm_value1_row3              0x491
#define addr_touch_edit_pgm_value2_row3              0x492
#define addr_touch_edit_pgm_hour_row3                0x493
#define addr_touch_edit_pgm_min_row3                 0x494
#define addr_touch_edit_pgm_sec_row3                 0x495
#define addr_touch_edit_pgm_ts1_row3                 0x496
#define addr_touch_edit_pgm_ts2_row3                 0x497
#define addr_touch_edit_pgm_ts3_row3                 0x498
#define addr_touch_edit_pgm_wt_row3                  0x499

#define addr_edit_pgm_step_row4                0x4A0
#define addr_edit_pgm_value1_row4              0x4A1
#define addr_edit_pgm_value2_row4              0x4A2
#define addr_edit_pgm_hour_row4                0x4A3
#define addr_edit_pgm_min_row4                 0x4A4
#define addr_edit_pgm_sec_row4                 0x4A5
#define addr_edit_pgm_ts1_row4                 0x4A6
#define addr_edit_pgm_ts2_row4                 0x4A7
#define addr_edit_pgm_ts3_row4                 0x4A8
#define addr_edit_pgm_wt_row4                  0x4A9

#define addr_touch_edit_pgm_value1_row4              0x4B1
#define addr_touch_edit_pgm_value2_row4              0x4B2
#define addr_touch_edit_pgm_hour_row4                0x4B3
#define addr_touch_edit_pgm_min_row4                 0x4B4
#define addr_touch_edit_pgm_sec_row4                 0x4B5
#define addr_touch_edit_pgm_ts1_row4                 0x4B6
#define addr_touch_edit_pgm_ts2_row4                 0x4B7
#define addr_touch_edit_pgm_ts3_row4                 0x4B8
#define addr_touch_edit_pgm_wt_row4                  0x4B9

#define addr_touch_edit_pgm_lastpage            0x4C1
#define addr_touch_edit_pgm_nextpage            0x4C1
#define addr_touch_edit_pgm_firstpage           0x4C1
#define addr_touch_edit_pgm_endpage             0x4C1
#define addr_touch_edit_pgm_newpgm              0x4C5
#define addr_touch_edit_pgm_delpgm              0x4C6
#define addr_touch_edit_pgm_insertsgm           0x4C7
#define addr_touch_edit_pgm_delsgm              0x4C8
#define addr_touch_edit_pgm_save                0x4C9

#define addr_onepoint_save_pgm                0x600
#define addr_onepoint_test_temperature        0x612
#define addr_onepoint_test_humidity           0x614
#define addr_onepoint_ramptime_hour           0x622
#define addr_onepoint_ramptime_min            0x624
#define addr_onepoint_ramptime_sec             0x626
#define addr_onepoint_constime_hour             0x632
#define addr_onepoint_constime_min              0x634
#define addr_onepoint_constime_sec              0x636
#define addr_onepoint_timesignal_1              0x642
#define addr_onepoint_timesignal_2              0x644
#define addr_onepoint_timesignal_3              0x646
#define addr_onepoint_wait                      0x652
#define addr_touch_onepoint_test_temperature        0x611
#define addr_touch_onepoint_test_humidity           0x613
#define addr_touch_onepoint_ramptime_hour           0x621
#define addr_touch_onepoint_ramptime_min            0x623
#define addr_touch_onepoint_ramptime_sec             0x625
#define addr_touch_onepoint_constime_hour             0x631
#define addr_touch_onepoint_constime_min              0x633
#define addr_touch_onepoint_constime_sec              0x635
#define addr_touch_onepoint_timesignal_1              0x641
#define addr_touch_onepoint_timesignal_2              0x643
#define addr_touch_onepoint_timesignal_3              0x645
#define addr_touch_onepoint_wait                      0x651





#endif // ADDRESS_DATA_SHOW_H
