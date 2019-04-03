debImport "+v2k" "-sverilog" "-full64" "-f" "../verilog/filelist.f"
debLoadSimResult \
           /home/zhou/work/arm/AT510-MN-80001-r2p0-00rel0/systems/cortex_m0_mcu/rtl_sim/tb_cmsdk_mcu.fsdb
wvCreateWindow
verdiDockWidgetDisplay -dock widgetDock_WelcomePage
verdiDockWidgetHide -dock widgetDock_WelcomePage
srcHBSelect "tb_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu" -delim "."
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_mcu" -delim "."
srcHBSelect "tb_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {34 54 3 7 5 25}
srcAddSelectedToWave -win $_nTrace1
wvZoomAll -win $_nWave2
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G1" 0)}
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu" -win $_nTrace1
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_mcu" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -signal "XTAL1" -win $_nTrace1
srcAddSelectedToWave -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "XTAL1" -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "FCLK" -win $_nTrace1
srcAddSelectedToWave -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "HCLK" -win $_nTrace1
srcAction -pos 197 3 1 -win $_nTrace1 -name "HCLK" -ctrlKey off
srcAddSelectedToWave -win $_nTrace1
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_mcu" -delim "."
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu.u_cmsdk_mcu_system" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu.u_cmsdk_mcu.u_cmsdk_mcu_system" -delim \
           "."
srcDeselectAll -win $_nTrace1
srcSelect -signal "FCLK" -win $_nTrace1
srcAddSelectedToWave -win $_nTrace1
debLoadSimResult \
           /home/zhou/work/arm/AT510-MN-80001-r2p0-00rel0/systems/cortex_m0_mcu/rtl_sim/tb_cmsdk_mcu.fsdb
srcDeselectAll -win $_nTrace1
srcSelect -signal "FCLK" -win $_nTrace1
srcAddSelectedToWave -win $_nTrace1
srcAddSelectedToWave -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -word -line 36 -pos 3 -win $_nTrace1
srcAction -pos 36 3 8 -win $_nTrace1 -name "\"cmsdk_mcu_defs.v\"" -ctrlKey off
srcBackwardHistory -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "DBGRESETn" -win $_nTrace1
srcAction -pos 62 5 7 -win $_nTrace1 -name "DBGRESETn" -ctrlKey off
srcBackwardHistory -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -signal "HCLK" -win $_nTrace1
wvSetPosition -win $_nWave2 {("G2" 0)}
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu.u_cmsdk_mcu_system.u_ahb_default_slave_1" \
           -win $_nTrace1
srcHBSelect "tb_cmsdk_mcu.u_cmsdk_mcu.u_cmsdk_mcu_system.u_addr_decode" -win \
           $_nTrace1
srcSetScope -win $_nTrace1 \
           "tb_cmsdk_mcu.u_cmsdk_mcu.u_cmsdk_mcu_system.u_addr_decode" -delim \
           "."
srcDeselectAll -win $_nTrace1
srcSelect -signal "haddr" -win $_nTrace1
wvSetPosition -win $_nWave2 {("G1" 0)}
wvSetPosition -win $_nWave2 {("G2" 0)}
srcHBSelect "tb_cmsdk_mcu" -win $_nTrace1
srcSetScope -win $_nTrace1 "tb_cmsdk_mcu" -delim "."
srcDeselectAll -win $_nTrace1
srcSelect -signal "TDI" -win $_nTrace1
wvSetPosition -win $_nWave2 {("G1" 0)}
wvSetPosition -win $_nWave2 {("G2" 0)}
wvAddSignal -win $_nWave2 "/tb_cmsdk_mcu/TDI"
wvSetPosition -win $_nWave2 {("G2" 0)}
wvSetPosition -win $_nWave2 {("G2" 1)}
wvSetPosition -win $_nWave2 {("G2" 1)}
debExit
