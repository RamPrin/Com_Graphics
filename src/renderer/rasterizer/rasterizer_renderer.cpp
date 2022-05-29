#include "rasterizer_renderer.h"

#include "utils/resource_utils.h"


void cg::renderer::rasterization_renderer::init()
{
	render_target = std::make_shared<cg::resource<cg::unsigned_color>>(settings->width, settings->height);
	rasterizer = std::make_shared<cg::renderer::rasterizer<cg::vertex, cg::unsigned_color>>();
	rasterizer->set_viewport(settings->width, settings->height);
	rasterizer->set_render_target(render_target);
	// TODO: Lab 1.03. Adjust `cg::renderer::rasterization_renderer` class to consume `cg::world::model`
	// TODO: Lab 1.04. Setup an instance of camera `cg::world::camera` class in `cg::renderer::rasterization_renderer`
	// TODO: Lab 1.06. Add depth buffer in cg::renderer::rasterization_renderer
}
void cg::renderer::rasterization_renderer::render()
{
	// TODO: Lab 1.03. Adjust `cg::renderer::rasterization_renderer` class to consume `cg::world::model`
	// TODO: Lab 1.04. Implement `vertex_shader` lambda for the instance of `cg::renderer::rasterizer`
	// TODO: Lab 1.05. Implement `pixel_shader` lambda for the instance of `cg::renderer::rasterizer`
	rasterizer->pixel_shader = [](cg::vertex vertex_data, float z) {
		return cg::color{
				vertex_data.ambient_r,
				vertex_data.ambient_g,
				vertex_data.ambient_b
		};
	};

	rasterizer->clear_render_target({255, 0, 0});

	cg::utils::save_resource(*render_target, settings->result_path);
}

void cg::renderer::rasterization_renderer::destroy() {}

void cg::renderer::rasterization_renderer::update() {}