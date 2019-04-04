debImport "+v2k" "-sverilog" "-full64" "-f" "../verilog/filelist.f"
debLoadSimResult \
           /home/zhou/work/arm_soc/systems/cortex_m0_mcu/rtl_sim/tb_cmsdk_mcu.fsdb
wvCreateWindow
verdiDockWidgetDisplay -dock widgetDock_WelcomePage
verdiDockWidgetHide -dock widgetDock_WelcomePage
srcHBSelect "tb_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu" -delim "."
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_mcu" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {48 59 1 1 1 1}
srcAddSelectedToWave -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {83 88 3 7 14 20}
srcAddSelectedToWave -win $_nTrace1
srcHBSelect "cmsdk_ahb_downsizer64" -win $_nTrace1
srcSetScope -win $_nTrace1 "cmsdk_ahb_downsizer64" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {49 56 5 14 18 4}
srcAddSelectedToWave -win $_nTrace1
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_clkreset" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_clkreset" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -signal "CLK" -win $_nTrace1
srcAddSelectedToWave -win $_nTrace1
srcHBSelect "tb_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu" -delim "."
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_uart_capture" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_uart_capture" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {46 51 5 15 5 9}
srcAddSelectedToWave -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {73 81 3 1 1 1}
srcAddSelectedToWave -win $_nTrace1
srcHBSelect "tb_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {44 49 4 1 1 1}
srcAddSelectedToWave -win $_nTrace1
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G1" 0)}
debExit
