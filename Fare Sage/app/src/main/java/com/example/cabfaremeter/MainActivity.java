package com.example.cabfaremeter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.Window;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_main);
    }
    @Override
    public void onBackPressed() {
        moveTaskToBack(true);
        finish();
    }
    public void about(View view){
        Intent i  = new Intent(getApplicationContext() , about.class);
        startActivity(i);
    }
    public void contact(View view){
        Intent i = new Intent(getApplicationContext(), contact.class);
        startActivity(i);
    }
    public void fare(View view)
    {
        Intent i = new Intent(getApplicationContext(), FareMeter.class);
        startActivity(i);
    }
}