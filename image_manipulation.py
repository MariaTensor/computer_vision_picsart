import cv2 as cv

img = cv.imread("/home/maria/Desktop/Picsart Academy /project_ds/"
                "pythonProject1/picture-a-captivating-scene-of-a-tranquil-lake-at-sunset-ai-generative-photo.jpg")
if img is None:
    print("Image is empty")
else:
    print("Image is not empty")

height, width = img.shape[:2]
res = cv.resize(img, (2 * width, 2 * height), interpolation=cv.INTER_CUBIC)
flip = cv.flip(img, 0)
flip1 = cv.flip(img, 1)
cropped = img[80:280, 150:330]
rotate = cv.rotate(img, cv.ROTATE_90_CLOCKWISE)

cv.imshow("cropped", cropped)
cv.imshow('flipped1', flip1)
cv.imshow('flipped', flip)
cv.imshow('image', res)
cv.imshow('rotated', rotate)
cv.waitKey(0)
# cv.destroyAllWindows()
resized = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/resized.jpg'
cv.imwrite(resized, res)
flipped = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/flipped.jpg'
cv.imwrite(flipped, flip)
flipped1 = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/flipped1.jpg'
cv.imwrite(flipped1, flip1)
cropped_image = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/cropped.jpg'
cv.imwrite(cropped_image, cropped)
rotated = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/rotated.jpg'
cv.imwrite(rotated, rotate)
