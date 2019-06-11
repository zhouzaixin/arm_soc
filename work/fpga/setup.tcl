set homedir [pwd]
set PRJ arm_soc
set SCRIPT_TEST arm_m0_soc
set TYPE xc7z020clg484-3

set_property SEVERITY {Warning} [get_drc_checks NSTD-1] 
set_property SEVERITY {Warning} [get_drc_checks RTSTAT-1]
set_property SEVERITY {Warning} [get_drc_checks UCIO-1]

##############################################################################
##############################################################################
##############################################################################
# STEP#1: define the output directory area.
set outputDir $homedir/$PRJ

create_project -force $PRJ $outputDir -part $TYPE

#mkdir $outputDir
#
# STEP#2: setup design sources and constraints
#
# VHDL
#
#指定需要添加的VHDL库文件，glob是扫描某个路径下的全部文件（这里是.vhdl文件）
#read_vhdl -library bftLib [ glob ./Sources/hdl/bftLib/*.vhdl ] 
#指定需要添加的VHDL文件
#read_vhdl ./Sources/hdl/bft.vhdl              
# ##############################
# Verilog HDL
#
#指定需要添加的Verilog文件，glob是扫描某个路径下的全部文件（这里是.v文件）
read_verilog  [ glob $homedir/rtl/*.v ]                
# ##############################
# XDC
#
#指定需要添加的xdc文件，glob是扫描某个路径下的全部文件（这里是.xdc文件）
read_xdc [ glob $homedir/const/*.xdc ]              
# ##############################
# EDIF and NGC
#
#指定需要添加的网表文件
#read_edif ../test.edif                          
# ##############################
# IP XCI
#
#指定需要添加的xci IP文件
#read_ip ./CORE/MMCM/MMCM.xci                    
# ##############################
# STEP#3: run synthesis, write design checkpoint, report timing,
# and utilization estimates
# 运行综合 ，同时设定相关综合参数
synth_design -top $SCRIPT_TEST      \
             -part $TYPE            \
             -fanout_limit 1000     \
             -shreg_min_size 3      \
             -flatten_hierarchy full
#存档
write_checkpoint -force $outputDir/post_synth.dcp 
#生成时序报告
report_timing_summary -file $outputDir/post_synth_timing_summary.rpt  
#生成资源使用报告  
report_utilization -file $outputDir/post_synth_util.rpt 
#
#
# STEP#4: run logic optimization, placement and physical logic optimization,
# write design checkpoint, report utilization and timing estimates
#
#优化设计
opt_design
#布局        
place_design
#生成资源使用报告      
report_clock_utilization -file $outputDir/clock_util.rpt
#存档    
write_checkpoint -force $outputDir/post_place.dcp
#生成时序报告       
report_timing_summary -file $outputDir/post_place_timing_summary.rpt 
#
# STEP#5: run the router, write the post-route design checkpoint, report the routing
# status, report timing, power, and DRC, and finally save the Verilog netlist.
#
#布线
route_design
 #存档      
write_checkpoint -force $outputDir/post_route.dcp
#报告布线状况
report_route_status -file $outputDir/post_route_status.rpt
#生成时序报告 
report_timing_summary -file $outputDir/post_route_timing_summary.rpt 
#生成功耗报告   
report_power -file $outputDir/post_route_power.rpt
#运行DRC 生成DRC检查报告  
report_drc -file $outputDir/post_imp_drc.rpt        
# write_verilog -force $outputDir/cpu_impl_netlist.v -mode timesim -sdf_anno true
#
# STEP#6: generate a bitstream
#
#生成bit文件
write_bitstream -force $outputDir/${SCRIPT_TEST}.bit  

write_sdf -force $outputDir/${SCRIPT_TEST}.sdf
  
##############################################################################
##############################################################################
##############################################################################