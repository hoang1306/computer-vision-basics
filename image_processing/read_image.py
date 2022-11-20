import cv2
import matplotlib.pyplot as plt

def reading_image(path):
    img = cv2.imread(filename=path, )
    cv2.imshow("image", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    path = 'gai.png'
    img = cv2.imread(filename=path, )
    # cv2.imshow("image", img)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()

    # reading_image(path)
    # print(img)
    height, weight, number_channels = img.shape
    size = img.size
    dtype = img.dtype
    print("height: ", height)
    print("weight", weight)
    print("number channels: ", number_channels)
    print("size: ", size)
    print("dtype: ", dtype)
    print("display rgb image: ", plt.imshow(img[:,:,::-1]))
    print(img[0, 0])