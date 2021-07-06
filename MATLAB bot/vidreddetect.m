obj=videoinput('winvideo',1);
obj.ReturnedColorspace = 'rgb';
B=getsnapshot(obj);

framesAcquired = 0;
while (framesAcquired <= 10) 
    
      data = getsnapshot(obj); 
      framesAcquired = framesAcquired + 1;    
      
      diff_im = imsubtract(data(:,:,1), rgb2gray(data)); 
      diff_im = medfilt2(diff_im, [3 3]);             
      diff_im = im2bw(diff_im,0.18);                   
      %stats = regionprops(diff_im, 'BoundingBox', 'Centroid'); 
      
  
      % Remove all those pixels less than 300px
      diff_im = bwareaopen(diff_im,300);
    
    % Label all the connected components in the image.
     bw = bwlabel(diff_im, 8);
    
    % Here we do the image blob analysis.
    % We get a set of properties for each labeled region.
    stats = regionprops(bw, 'BoundingBox', 'Centroid');
    
    % Display the image
    imshow(data)
    
    hold on
    
    %This is a loop to bound the red objects in a rectangular box.
    for object = 1:length(stats)
        bb = stats(object).BoundingBox;
        rectangle('Position',bb,'EdgeColor','r','LineWidth',2)
    end  
 
    hold off
    
end

clear all