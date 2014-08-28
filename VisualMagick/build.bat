msbuild /m VisualStaticMT.sln /t:Rebuild /p:Configuration=Release,Platform=Win32
msbuild /m VisualDynamicMT.sln /t:Rebuild /p:Configuration=Release,Platform=Win32
msbuild /m VisualStaticMT.sln /t:Rebuild /p:Configuration=Release,Platform=x64
msbuild /m VisualDynamicMT.sln /t:Rebuild /p:Configuration=Release,Platform=x64
