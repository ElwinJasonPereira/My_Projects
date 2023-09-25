package com.example.cabfaremeter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.Window;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;

import com.airbnb.lottie.LottieAnimationView;

public class splash extends AppCompatActivity {
    private static int SPLASH_SCREEN=3500;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_splash);
        LottieAnimationView animationView1 = findViewById(R.id.animation_new);
        animationView1.setAnimation(R.raw.anim1);
        animationView1.playAnimation();
        LottieAnimationView animationView = findViewById(R.id.animation_old);
        animationView.setAnimation(R.raw.anim2);
        animationView.playAnimation();
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