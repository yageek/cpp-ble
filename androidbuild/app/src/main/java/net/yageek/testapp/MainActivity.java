package net.yageek.testapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import net.yageek.cppble.ScanningHelper;
import net.yageek.cppble.mainlibcode.TestLibCall;

import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    public final TestLibCall lib = new TestLibCall();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        lib.startScan();
    }

}
