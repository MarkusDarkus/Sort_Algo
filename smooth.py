import numpy as np


def window(y, box_pts):
    box = np.ones(box_pts)/box_pts
    y_smooth = np.convolve(y, box, mode='same')
    return y_smooth

def smooth(array):
    array = window(array, 19)   #19 или другое число юзай, чем больше тем глаже
    return


