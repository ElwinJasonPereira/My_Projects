package com.example.cabfaremeter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.Window;

import com.airbnb.lottie.LottieAnimationView;

public class logfailure extends AppCompatActivity {
    private static int SPLASH_SCREEN=2000;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_logfailure);
        LottieAnimationView animationView1 = findViewById(R.id.animation);
        animationView1.setAnimation(R.raw.anim5);
        animationView1.playAnimation();
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                String email = getIntent().getStringExtra("email");
                String pass = getIntent().getStringExtra("password");
                Intent i = new Intent(getApplicationContext(),signup.class);
                i.putExtra("email",email);
                i.putExtra("password",pass);
                startActivity(i);
                finish();
            }
        },SPLASH_SCREEN);
    }
}