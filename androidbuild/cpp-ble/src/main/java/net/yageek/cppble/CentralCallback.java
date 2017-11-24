package net.yageek.cppble;

import android.annotation.TargetApi;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanResult;
import android.os.Build;
import android.util.Log;

import java.util.List;

/**
 * Created by yheinrich on 22.08.17.
 */

@TargetApi(Build.VERSION_CODES.LOLLIPOP)
public class CentralCallback extends ScanCallback {

    @Override
    public void onScanResult(int callbackType, ScanResult result) {
        Log.d("CPP_BLE", String.format("Device Name: %s", result.getDevice().getName()));
    }

    @Override
    public void onBatchScanResults(List<ScanResult> results) {

    }

    @Override
    public void onScanFailed(int errorCode) {
        Log.d("CPP_BLE", String.format("Error code %i", errorCode));
    }


}
