import numpy
import cv2

img = cv2.imread('pc1.png')

#access and modify the pixel of image with two ways
px = img[100,100]
print(px)

blue = img[100,100,0]
print(img.item(100,100,0))
print(blue)

img[100,100] = [255,255,255]
img.itemset((100,100,0),5)
print(img.item(100,100,0))
print(img[100,100])

print(img.shape)
print(img.size)
print(img.dtype)

img = cv2.imread('pc1.png')
part = img[0:120,0:160]
img[120:240,160:320] = part
cv2.imshow('pic',img)
cv2.waitKey(0)
