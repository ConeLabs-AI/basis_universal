#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "encoder/basisu_comp.h"

namespace py = pybind11;

// THIS IS A PLACEHOLDER - We nede an actual function according to the "low-level C++ API" example in the README
/*
Eg.
bool test()
{
	basisu_encoder_init();

	image img;
	if (!load_image("test.png", img))
	{
		printf("Can't load image\n");
		return false;
	}

	basis_compressor_params basisCompressorParams;

	basisCompressorParams.m_source_images.push_back(img);
	basisCompressorParams.m_perceptual = false;
	basisCompressorParams.m_mip_srgb = false;

	basisCompressorParams.m_write_output_basis_files = true;
	basisCompressorParams.m_out_filename = "test.basis";

	basisCompressorParams.m_uastc = true;
	basisCompressorParams.m_rdo_uastc_multithreading = false;
	basisCompressorParams.m_multithreading = false;
	basisCompressorParams.m_debug = true;
	basisCompressorParams.m_status_output = true;
	basisCompressorParams.m_compute_stats = true;
	
	basisu::job_pool jpool(1);
	basisCompressorParams.m_pJob_pool = &jpool;

	basisu::basis_compressor basisCompressor;
	basisu::enable_debug_printf(true);

	bool ok = basisCompressor.init(basisCompressorParams);
	if (ok)
	{
		basisu::basis_compressor::error_code result = basisCompressor.process();

		if (result == basisu::basis_compressor::cECSuccess)
			printf("Success\n");
		else
		{
			printf("Failure\n");
			ok = false;
		}
	}
	else
		printf("Failure\n");
	return ok;
}

*/
PYBIND11_MODULE(basis_compressor, m) {
    py::class_<basisu::basis_compressor>(m, "BasisCompressor")
        .def(py::init<>())
        .def("process_buffers", &basisu::basis_compressor::process_buffers,
             "Compress a PNG buffer and return the compressed data");
}