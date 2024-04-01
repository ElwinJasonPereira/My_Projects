package com.example.cabfaremeter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.Window;

import com.airbnb.lottie.LottieAnimationView;

public class signsuccess extends AppCompatActivity {
    private static int SPLASH_SCREEN=3500;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_signsuccess);
        LottieAnimationView animationView1 = findViewById(R.id.animation);
        animationView1.setAnimation(R.raw.anim4);
        animationView1.playAnimation();
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                Intent i = new Intent(getApplicationContext(),login.class);
                startActivity(i);
                finish();
            }
        },SPLASH_SCREEN);
    }
}