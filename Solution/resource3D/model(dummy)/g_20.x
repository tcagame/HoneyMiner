xof 0303txt 0032
Material lambert30 {
	1.000000;1.000000;1.000000;1.000000;;
	0.000000;
	0.000000;0.000000;0.000000;;
	0.000000;0.000000;0.000000;;
	TextureFilename {
		"..\\stage_tex.jpg";
	}
}
Frame mountain_20_GEO {
	FrameTransformMatrix {
		1.000000,0.000000,0.000000,0.000000,
		0.000000,1.000000,0.000000,0.000000,
		0.000000,0.000000,1.000000,0.000000,
		0.000000,0.000000,0.000000,1.000000;;
	}
	Mesh {
		4;
		-5.000000;30.000000;-0.000000;,
		5.000000;30.000000;-0.000000;,
		5.000000;20.000000;10.000000;,
		-5.000000;20.000000;10.000000;;
		2;
		3;0,2,1;,
		3;0,3,2;;
		MeshNormals {
			4;
			0.000000;0.707107;0.707107;,
			0.000000;0.707107;0.707107;,
			0.000000;0.707107;0.707107;,
			0.000000;0.707107;0.707107;;
			2;
			3;0,2,1;,
			3;0,3,2;;
		}
		MeshTextureCoords {
			4;
			0.872107;0.456987;,
			0.884876;0.456987;,
			0.884876;0.444218;,
			0.872107;0.444218;;
		}
		MeshMaterialList {
			1;
			2;
			0,
			0;
			{lambert30}
		}
	}
}
AnimationSet Take_001 {
}