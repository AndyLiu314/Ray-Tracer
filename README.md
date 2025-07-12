# Ray-Tracer
## Made By: Andy Liu

**Overview:**
This project is a basic ray tracer written in C++ that renders 3D scenes by simulating the way light rays interact with objects. It uses fundamental geometric and linear algebra concepts such as vectors, dot products, and reflection/refraction equations to compute ray-object intersections and light behavior. Rays are traced from a virtual camera through each pixel, recursively bouncing off surfaces based on material properties (Lambertian, metallic, or dielectric), with colour computed through light attenuation at each bounce. Anti-aliasing is achieved via stochastic sampling, and defocus blur (depth of field) is simulated using a thin lens model with rays randomly sampled within an aperture. The project is fully implemented from scratch with no external libraries, relying on custom math routines and a simple PPM image output format.

**Example Outputs:**
<br>![scene(med-sample)](https://github.com/user-attachments/assets/5fd707a6-8083-4334-9d14-a6d4fa1b3c03)
<br>![scene (med-sample-centered)](https://github.com/user-attachments/assets/c377ddb4-001a-415f-9ad9-0acbeeaa0278)

