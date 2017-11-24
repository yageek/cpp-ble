package net.yageek.cppble;

import android.annotation.TargetApi;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.os.Build;
import android.util.Log;

/**
 * Created by yheinrich on 22.08.17.
 */

@TargetApi(Build.VERSION_CODES.JELLY_BEAN_MR2)
public class CentralCallbackLegacy implements BluetoothAdapter.LeScanCallback {
    static {
        System.loadLibrary("cpp-ble");
    }
    @Override
    public void onLeScan(BluetoothDevice device, int rssi, byte[] scanRecord) {
        Log.d("CPP_BLE", String.format("Device Name: %s", device.getName()));
        if(device.getName() != null) {
            onScanResultProxy(device.getName());
        }

    }
    public native void onScanResultProxy(String name);
}
