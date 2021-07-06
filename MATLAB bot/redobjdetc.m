data = imread('g.png');
    diff_im = imsubtract(data(:,:,3), rgb2gray(data));
    %Use a median filter to filter out noise
    diff_im = medfilt2(diff_im, [3 3]);
    diff_im = im2bw(diff_im,0.18);
    
    diff_im = bwareaopen(diff_im,300);
    
    bw = bwlabel(diff_im, 8);
    
    stats = regionprops(bw, 'BoundingBox', 'Centroid');
    
    % Display the image
    imshow(data)
    
    hold on
 
    for object = 1:length(stats)
        bb = stats(object).BoundingBox;
        rectangle('Position',bb,'EdgeColor','r','LineWidth',2)
    end
    
    hold off