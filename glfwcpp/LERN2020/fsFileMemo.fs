
// Sample

#version 330 core
out vec4 FragColor;
in vec3 ourColor;
in vec3 ourPos;
void main()
{
    FragColor = vec4(ourPos, 1.0f);
}


// comment
1   out 変数に代入したデータは、レンダリングパイプラインの次のステージに送られます。
    フラグメントシェーダの out 変数に代入した値は、フレームバッファのカラーバッファに格納さ れます。


