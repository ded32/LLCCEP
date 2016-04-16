package ru.bezzubtsev.executor;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.io.File;

public class Selection extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_selection);

        GetEnvironmentFiles();
    }

    public void Launch(String paths[], boolean JIT) {

    }

    private String GetEnvironmentDirectory() {
        String directory = Environment.getRootDirectory().toString() + "/apps/SiLang/exector/programs/";
        Log.d("Environment directory", "Directory: " + directory);
        return directory;
    }

    public String[] GetEnvironmentFiles() {
        File file = new File(GetEnvironmentDirectory());
        File files[] = file.listFiles();

        String paths[] = new String[files.length];

        for (int i = 0; i < files.length; i++) {
            Log.d("Containing", "File: " + files[i].getAbsolutePath());
            paths[i] = files[i].getAbsolutePath();
        }

        return paths;
    }
}
