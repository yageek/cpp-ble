package net.yageek.cppble;

import android.annotation.TargetApi;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.bluetooth.le.BluetoothLeScanner;
import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanSettings;
import android.content.Context;
import android.content.Intent;
import android.os.Build;

import java.util.UUID;

/**
 * Created by yheinrich on 18.08.17.
 */

public class ScanningHelper {
    private final BluetoothAdapter mBluetoothAdapter;

    private ScanningHelper() {
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
    }

    public static ScanningHelper getScanningHelper() {
        return new ScanningHelper();
    }

    public boolean scanForBLE(){
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR2) {
            return scanForBLELegacy(null);
        }
        return scanForBLENew(null);
    }


    @TargetApi(Build.VERSION_CODES.LOLLIPOP)
    private boolean scanForBLENew(UUID[] uuids) {
        BluetoothLeScanner scanner = mBluetoothAdapter.getBluetoothLeScanner();
        scanner.startScan(new CentralCallback());
        return true;
    }

    private boolean scanForBLELegacy(UUID[] uuids) {
        mBluetoothAdapter.startLeScan(new CentralCallbackLegacy());
        return true;
    }

}

