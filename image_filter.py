import cv2 as cv
import numpy as np

img = cv.imread("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/free-nature-images.jpg")
img_for_median = cv.imread("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/1 2I9jCD3ZuQd-SUhC21ra8Q.jpg")
if img is None:
    print("Image is empty")
else:
    print("Image is not empty")
rgb_img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
hsv_img = cv.cvtColor(img, cv.COLOR_BGR2HSV)
lab_img = cv.cvtColor(img, cv.COLOR_BGR2LAB)
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
blur_img = cv.GaussianBlur(img, (5, 5), 0)
kernel = np.array([[-1, -1, -1],
                             [-1, 9, -1],
                             [-1, -1, -1]])
sharp_img = cv.filter2D(img, -1, kernel)
median_img = cv.medianBlur(img_for_median, 3)

cv.imshow('sharp', sharp_img)
cv.imshow("rgb", rgb_img)
cv.imshow("img", img)
cv.imshow("hsv", hsv_img)
cv.imshow("lab", lab_img)
cv.imshow("gray", gray_img)
cv.imshow("blur",blur_img)
cv.imshow("median",median_img)
cv.imshow("imagetwo",img_for_median)
cv.waitKey(0)
# cv.destroyAllWindows()


rgb = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/rgb.jpg'
hsv = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/hsv.jpg'
lab = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/lab.jpg'
gray = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/gray.jpg'
blur = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/blur.jpg'
sharp = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/sharp.jpg'
cv.imwrite(hsv, hsv_img)
cv.imwrite(rgb, rgb_img)
cv.imwrite(lab, lab_img)
cv.imwrite(gray, gray_img)
cv.imwrite(blur, blur_img)
cv.imwrite(sharp,sharp_img)
