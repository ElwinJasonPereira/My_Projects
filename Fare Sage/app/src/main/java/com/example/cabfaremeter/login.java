package com.example.cabfaremeter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.widget.EditText;
import android.widget.Toast;

public class login extends AppCompatActivity {
    EditText email , password;
    Database database;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_login);
        email = findViewById(R.id.email2);
        password = findViewById(R.id.pass2);
        database = new Database(this);
    }
    public void login(View view)
    {
        String em2=email.getText().toString();
        String pass2=password.getText().toString();
        if(em2.isEmpty() || pass2.isEmpty()){
            Toast.makeText(getApplicationContext(), "Please fill in both email and password field to proceed", Toast.LENGTH_SHORT).show();
            return;
        }
        boolean userExists = database.checkUser(em2 , pass2);
        if(userExists){
            email.setText("");
            password.setText("");
            Toast.makeText(getApplicationContext(), "Login Successful", Toast.LENGTH_SHORT).show();
            Intent i = new Intent(getApplicationContext() , logsuccess.class);
            startActivity(i);
        }
        else{
            email.setText("");
            password.setText("");
            Toast.makeText(getApplicationContext(), "User does not exist\n\t\t\tSign in now", Toast.LENGTH_SHORT).show();
            Intent i = new Intent(getApplicationContext() , logfailure.class);
            i.putExtra("email",em2);
            i.putExtra("password",pass2);
            startActivity(i);
        }
    }
    public void sign(View view){
        Intent i = new Intent(getApplicationContext() , signup.class);
        startActivity(i);
    }
    public void free(View view){
        Intent i  = new Intent(getApplicationContext() , MainActivity.class);
        startActivity(i);
    }
}