#ifndef _RENDERER_H_
#define _RENDERER_H_


#include "Scene.h"
#include "Camera.h"
#include "ImagePlane.h"
#include "HitRecord.h"
#include "Image.h"
#include "Spectrum.h"


/*
 *
 */
class Renderer {

	public:
	
		// Constructor.
		inline Renderer(const Scene* scene, const Camera* camera, const ImagePlane* imgpl);

		// Ray-tracing algorithm.
		void render();
	
	private:

		void compute_ray_direction(Ray* ray, unsigned i, unsigned j);
		bool compute_ray_intersection(const Ray& ray, HitRecord* hit_rec);
		void compute_surface_shading(const HitRecord& hit_rec, Spectrum* colour);

		void set_pixel(Image<byte>& output, unsigned i, unsigned j, const Spectrum& colour);
		
		const Scene* scene;
		const Camera* cam;
		const ImagePlane* imgpl;
		
};


// Inline implementations:


/*
 * Constructor.
 */
inline
Renderer::Renderer(const Scene* _scene, const Camera* _camera, const ImagePlane* _imgpl)
	: scene(_scene), cam(_camera), imgpl(_imgpl)
{}
	


#endif // _RENDERER_H_
