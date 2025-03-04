# OpenVINO-GenAI-Samples

## OpenVINO™ GenAI 安装与配置

### 4.1 OpenVINO™ GenAI 下载与安装

&emsp;    首先访问下面链接，进入下载页面：

```
https://www.intel.com/content/www/us/en/developer/tools/openvino-toolkit/download.html
```

&emsp;    然后再下载页面选择相应的包以及环境，然后点击下载链接进行下载，如下图所示：

![1741082741034](https://ygj-images-container.oss-cn-nanjing.aliyuncs.com/BlogGallery/202503041805041.png)

&emsp;    文件下载完成后，将其解压到任意目录，此处建议解压到``C:\Program Files\Intel``目录下，并将文件夹名修改为较为简洁表述，如下图所示：

![1741082851324](https://ygj-images-container.oss-cn-nanjing.aliyuncs.com/BlogGallery/202503041807489.png)

&emsp;    最后在环境变量PATH中添加以下路径：

```
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\bin\intel64\Debug
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\bin\intel64\Release
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\3rdparty\tbb\bin
```

至此为止，我们便完成了OpenVINO™ GenAI 下载与安装。

### 4.2 OpenVINO™ GenAI C++项目配置

&emsp;    C++项目主要是需要配置包含目录、库目录以及附加依赖项，分别在C++项目中依次进行配置就可以：

- 包含目录：

```
# Debug和Release
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\include
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\include\openvino\genai
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\include\openvino
```

- 库目录：

```
# Debug
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\lib\intel64\Debug
# Release
C:\Program Files\Intel\openvino_genai_windows_2025.0.0.0_x86_64\runtime\lib\intel64\Release
```

- 附加依赖项

```
# Debug
openvinod.lib
openvino_genaid.lib
# Release
openvino.lib
openvino_genai.lib
```





### OpenCV 配置

```
C:\Program Files\Intel\opencv_4.11.0\build\include
```





```
C:\Program Files\Intel\opencv_4.11.0\build\x64\vc16\lib
```





```

# Debug
opencv_world4110d.lib
# Release
opencv_world4110.lib
```

