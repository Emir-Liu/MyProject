import cv2
import numpy as np
from matplotlib import pyplot as plt

#显示的行列，用于比较处理过程
row = 2
col = 2
#载入图片的地址
img_path = "./sudoku.jpg"

#载入原始图像
pic_orig = cv2.imread(img_path,-1)
#将原始BGR图像转换为灰度图
pic_gray = cv2.cvtColor(pic_orig,cv2.COLOR_BGR2GRAY)
#模糊化，降低自适应阈值处理时的噪声,这里是高斯滤波函数
pic_blur = cv2.GaussianBlur(pic_gray,(5,5),0)
#大津二值化算法来确定阈值
ret,pic_thre = cv2.threshold(pic_blur,0,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)
#膨胀来使轮廓更加明显
#kernel = np.ones((3,3),np.uint8)
#pic_eros = cv2.dilate(pic_thre,kernel,iterations = 1)
#进行轮廓操作
contours,hierarchy = cv2.findContours(pic_thre,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
#在窗口中绘制轮廓
cv2.drawContours(pic_orig,contours,1,(0,0,255),3)

print(len(contours))

#输出图片
titles = ['pic_gray','pic_blur','pic_thre','pic_cont']
images = [pic_gray,pic_blur,pic_thre,pic_orig]
for i in range(row):
    for j in range(col):
        tmp = i*row+j
        if tmp >= len(titles):
            break;
        plt.subplot(row*100+col*10+tmp+1)
        plt.imshow(images[tmp],'gray')
        plt.xticks([])
        plt.yticks([]) # to hide tick values on X and Y axis
plt.show()

