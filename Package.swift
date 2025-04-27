// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterScheme",
    products: [
        .library(name: "TreeSitterScheme", targets: ["TreeSitterScheme"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterScheme",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterSchemeTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterScheme",
            ],
            path: "bindings/swift/TreeSitterSchemeTests"
        )
    ],
    cLanguageStandard: .c11
)
