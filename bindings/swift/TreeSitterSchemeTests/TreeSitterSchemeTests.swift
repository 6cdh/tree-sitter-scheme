import XCTest
import SwiftTreeSitter
import TreeSitterScheme

final class TreeSitterSchemeTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_scheme())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Scheme grammar")
    }
}
