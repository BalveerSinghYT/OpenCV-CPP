# OpenCV-CPP
This is a repository related to OpenCV-C++ Course that I learned from www.computervsion.zone 

## Chapter List

1. **Chapter 1 - (Loading Image/Video):**
   - In this chapter, I learned how to read & display images/videos from a source file & using a web camera.
     
2. **Chapter 2 - (Image Processing):**
   - Concept covered: Color conversion, blurring an image, Edge Detection, Dilation & Erosion
     
3. **Chapter 3 - (Resize & Crop):**
   - Resized the image using width, height & fixed ratio
   - Cropped image using ROI(Region of Interest)
     
4. **Chapter 4 - (Drawing Shapes & Text):**
   - Created a logo using circles, rectangles, lines & text.
     
5. **Chapter 5 - (Warp Perspective):**
   - Step1: Define  source & destination points
   - Step2: Get Perspective Transformation matrix
   - Step3: Apply Warp Perspective
   - Step4: Plot points on the original image to show the selected points
   - Step5: Display the Original Image, Wrapped Images

6. **Chapter 6 - (Color Detection):**
   - detected colors using HSV Thresholding method
   - created trackbars to play with the different HSV values
  
7. **Chapter 7 - (Contour Detection & Shape Detection):**
   - Step 1: Preprocessing(binary image): BGR2GRAY, Gaussian Blur, Canny Edge Detection, Dilation
   - Step 2: Find the contours using findContours() in binary Image
   - Step 3: Add threshold condition to get contour if the size of the contour is matched
   - Step 4: Calculate perimeter using arclenth() & approximate the contour with polygon
   - Step 5: Calculate the bounding rectangle for the polygon & determine the no. of corners of a polygon
   - Step 6: Classify the shape based on no. of corners & check the aspect ratio in order to differentiate between square & rectangle
   - Step 7: Draw the contour and bounding rectangle on the original image
  
8. **Chapter 8 - (Face Detection):**
   - Load the image & pre-trained haarcascade_frontalface_default.xml model
   - use the detectMultiScale method of CascadeClassifier to detect faces
   - draw the rectangle on the detected faces
