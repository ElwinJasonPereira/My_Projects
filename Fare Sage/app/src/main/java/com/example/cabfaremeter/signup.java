package com.example.cabfaremeter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.regex.Pattern;

public class signup extends AppCompatActivity {
    EditText email, password;
    String em1 , pass1;
    Database database;
    int err = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_signup);
        email = findViewById(R.id.email1);
        password = findViewById(R.id.pass1);
        database = new Database(this);
        if(err == 0){
            email.setText(getIntent().getStringExtra("email"));
            password.setText(getIntent().getStringExtra("password"));
        }
    }
    @Override
    public void onBackPressed()
    {
        moveTaskToBack(true);
        finish();
    }
    public void signup(View view){
        String em1 = email.getText().toString();
        String pass1 = password.getText().toString();
        if(em1.isEmpty() || pass1.isEmpty()){
            Toast.makeText(getApplicationContext(), "Please fill in both email and password field to proceed", Toast.LENGTH_SHORT).show();
            return;
        }
        if (!isValidPassword(pass1)) {
            err = 1;
            Toast.makeText(getApplicationContext(), "Password Does not match the rules",Toast.LENGTH_SHORT).show();
            return;
        }
        database.insertUser(em1 , pass1);
        Intent i = new Intent(getApplicationContext(), signsuccess.class);
        startActivity(i);
    }
    Pattern lowercase = Pattern.compile("^.*[a-z].*$");
    Pattern uppercase = Pattern.compile("^.*[A-Z].*$");
    Pattern number = Pattern.compile("^.*[0-9].*$");
    Pattern specialCharacter = Pattern.compile("^.*[^a-zA-Z0-9].*$");
    private Boolean isValidPassword(String password) {
        if (password.length() < 8) {
            return false;
        }
        if (!lowercase.matcher(password).matches()) {
            return false;
        }
        if (!uppercase.matcher(password).matches()) {
            return false;
        }
        if (!number.matcher(password).matches()) {
            return false;
        }
        if (!specialCharacter.matcher(password).matches()) {
            return false;
        }
        return true;
    }
    public void log(View view){
        Intent i = new Intent(getApplicationContext() , login.class);
        startActivity(i);
    }
}