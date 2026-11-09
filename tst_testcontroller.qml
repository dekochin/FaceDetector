import QtQuick
import QtTest

TestCase {
    name: "TestController"

    function test_case1() {
        compare(1 + 1, 2, "sanity check");
        verify(true);
    }
}
