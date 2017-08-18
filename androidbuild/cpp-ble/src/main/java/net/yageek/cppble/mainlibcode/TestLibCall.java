package net.yageek.cppble.mainlibcode;

/**
 * Created by yheinrich on 18.08.17.
 */

public class TestLibCall {
    static {
        System.loadLibrary("cpp-ble");
    }

    public native void startScan();
}
