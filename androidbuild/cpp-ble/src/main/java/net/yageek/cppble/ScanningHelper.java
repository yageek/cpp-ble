package net.yageek.cppble;

import android.bluetooth.BluetoothAdapter;

/**
 * Created by yheinrich on 18.08.17.
 */

public class ScanningHelper {
    private final BluetoothAdapter mBluetoothAdapter;

    public ScanningHelper() {
        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
    }

    public boolean scanForBLE(){
        return false;
    }

}
