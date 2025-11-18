https://raytracing.github.io/books/RayTracingInOneWeekend.html

CPU-based ray tracer showcasing diffuse, reflectation, and refractive properties. Outputs a ppm image file with a 16:9 aspect ratio. Done on a M2 Macbook Pro.

This is written to a standard output stream, you would need to redirect to an image format.

On Mac, the commands I used were:

xcodebuild -project RayTracing.xcodeproj (build)

./build/Release/RayTracing > image.ppm (output)

On Windows, you debug the build using CMake commands. 

cmake --build build --config release (build)

build\Release\RayTracing.exe > image.ppm
