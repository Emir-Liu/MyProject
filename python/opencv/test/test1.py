import cv2
from matplotlib import pyplot as plt

img_path = "./pc1.png"

img = cv2.imread(img_path,0)

plt.imshow(img,cmap = 'gray',interpolation='bicubic')
plt.xticks([])
plt.yticks([]) # to hide tick values on X and Y axis
plt.show()

