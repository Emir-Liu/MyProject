#panda1.py
import pandas as pd

io_out = r'C:\Users\ABC\Desktop\personal\python\panda\list\托外加工单.xlsx'
io_dev = r'C:\Users\ABC\Desktop\personal\python\panda\list\送货清单.xlsx'
io_pur = r'C:\Users\ABC\Desktop\personal\python\panda\list\采购单.xlsx'
io_wee = r'C:\Users\ABC\Desktop\personal\python\panda\list\周计划.xlsx'

 
out_data = pd.read_excel(io_out,sheet_name = 0,header = 1,index_col = 0)
dev_data = pd.read_excel(io_dev,sheet_name = 0,header = 1,index_col = 1)
pur_data = pd.read_excel(io_pur,sheet_name = 0,header = 1,index_col = 0)
wee_data = pd.read_excel(io_wee,sheet_name = 0,header = 1,index_col = 0)

print('托外加工单')
print(out_data.head())
print('送货清单')
print(dev_data.head())
print('采购单')
print(pur_data.head())

print('获取到的所有数据：\n',format(out_data))


