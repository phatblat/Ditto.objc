// swift-tools-version:5.5

import PackageDescription

let package = Package(
    name: "Ditto.objc",
    platforms: [ .iOS(.v11), .macOS(.v11) ],
    products: [
        .library(
            name: "Ditto.objc",
            targets: ["Ditto.objc"]),
    ],
    targets: [
        .binaryTarget(
            name: "Ditto.objc",

            // url: "https://software.ditto.live/cocoa/DittoObjC/1.0.19/dist/DittoObjC-dist.tar.gz",
            // checksum: bbaec34d74b268be0df6b6664896c1ea26f145237bfb247e82811e4722a36b78

            url: "https://github.com/phatblat/Ditto.objc/releases/download/1.0.19/DittoObjC.xcframework.zip",
            checksum: "08526a7e68415e2499674d171fd929e6c8cf3571581a8e7d7619d735e7612770"
        )
    ]
)
