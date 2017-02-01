# HDR-Image-Composition

The project aims to take multiple images of varying exposure and compose a HDR Image out of it.

The 8 bit image is first linearly regressed to obtain the parameters that convert it to actual incident brightness.
These values are then experimented with 3 different algorithms:
 * a. Choosing the maximum unsaturated brightness from all images for every pixel
 * b. Average of unsaturated brightness of all images for every pixel
 * c. Weighted average of pixel depending on exposure and noise variance such that the weights add upto 1

The actual brightness HDR image is then tonemapped to obtain the 8 bit image
