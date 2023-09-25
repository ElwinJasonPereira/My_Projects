package com.example.cabfaremeter;

import android.content.Context;
import android.content.Intent;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.List;
import java.util.Locale;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

import java.text.DecimalFormat;

public class FareMeter extends AppCompatActivity {
    EditText source, destination;
    String src, dest;
    TextView result, resultdist;
    double totalfare, minfare = 25;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_fare_meter);
        source = findViewById(R.id.source);
        destination = findViewById(R.id.destination);
        result = findViewById(R.id.result);
        resultdist = findViewById(R.id.resultdist);
    }
    public void calculate(View view) {
        src = source.getText().toString();
        dest = destination.getText().toString();
        if(src.isEmpty() || dest.isEmpty()){
            Toast.makeText(getApplicationContext(), "Please enter both source and destination to proceed", Toast.LENGTH_SHORT).show();
            return;
        }
        else{
            calculateDistance(getApplicationContext(), src, dest);
        }
    }

    private void calculateDistance(Context context, String sourceAddress, String destinationAddress) {
        Geocoder geocoder = new Geocoder(context, Locale.getDefault());
        try {
            List<Address> sourceAddresses = geocoder.getFromLocationName(sourceAddress, 1);
            List<Address> destinationAddresses = geocoder.getFromLocationName(destinationAddress, 1);

            if (sourceAddresses != null && destinationAddresses != null && sourceAddresses.size() > 0 && destinationAddresses.size() > 0) {
                Address source = sourceAddresses.get(0);
                Address destination = destinationAddresses.get(0);
                double sourceLat = source.getLatitude();
                double sourceLong = source.getLongitude();
                double destinationLat = destination.getLatitude();
                double destinationLong = destination.getLongitude();
                float[] results = new float[1];
                Location.distanceBetween(sourceLat, sourceLong, destinationLat, destinationLong, results);
                double distance = results[0] / 1000.0;
                getResult(distance);
            }
            else{
                getResult(-1);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void osm(View view) {
        src = source.getText().toString();
        dest = destination.getText().toString();
        if(src.isEmpty() || dest.isEmpty()){
            Toast.makeText(getApplicationContext(), "Please enter both source and destination to proceed", Toast.LENGTH_SHORT).show();
            return;
        }
        else{
            osmDistance(getApplicationContext(), src, dest);
        }
    }

    private void osmDistance(Context context, String sourceAddress, String destinationAddress) {
        Geocoder geocoder = new Geocoder(context, Locale.getDefault());
        try {
            List<Address> sourceAddresses = geocoder.getFromLocationName(sourceAddress, 1);
            List<Address> destinationAddresses = geocoder.getFromLocationName(destinationAddress, 1);
            if (sourceAddresses != null && destinationAddresses != null && sourceAddresses.size() > 0 && destinationAddresses.size() > 0) {
                Address source = sourceAddresses.get(0);
                Address destination = destinationAddresses.get(0);
                double sourceLat = source.getLatitude();
                double sourceLong = source.getLongitude();
                double destinationLat = destination.getLatitude();
                double destinationLong = destination.getLongitude();
                OkHttpClient client = new OkHttpClient();
                String url = "https://router.project-osrm.org/route/v1/driving/" + sourceLong + "," + sourceLat + ";" + destinationLong + "," + destinationLat + "?overview=false";
                Request request = new Request.Builder().url(url).build();
                client.newCall(request).enqueue(new Callback() {
                    @Override
                    public void onFailure(Call call, IOException e) {
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                Toast.makeText(getApplicationContext(), "Failed to retrieve data. Please check your internet connection and try again.", Toast.LENGTH_SHORT).show();
                                result.setText("NA");
                                resultdist.setText("NA");
                            }
                        });
                    }

                    @Override
                    public void onResponse(Call call, Response response) throws IOException {
                        if (response.isSuccessful()) {
                            String responseData = response.body().string();
                            try {
                                JSONObject responseJson = new JSONObject(responseData);
                                JSONArray routes = responseJson.getJSONArray("routes");
                                if (routes.length() > 0) {
                                    JSONObject route = routes.getJSONObject(0);
                                    double distance = route.getDouble("distance");
                                    distance /= 1000.0;
                                    getResult(distance);
                                }
                            } catch (JSONException e) {
                                Toast.makeText(getApplicationContext(),"Exception occured", Toast.LENGTH_SHORT).show();
                            }
                        }else {
                            runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                Toast.makeText(getApplicationContext(), "No route available between the source and destination", Toast.LENGTH_SHORT).show();
                                result.setText("NA");
                                resultdist.setText("NA");
                            }
                        });
                        }
                    }
                });
            }
            else {
                getResult(-1);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void getResult(double distance) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if (distance == -1) {
                    Toast.makeText(getApplicationContext(), "Enter the correct source and destination", Toast.LENGTH_SHORT).show();
                    result.setText("NA");
                    resultdist.setText("NA");
                } else if (distance == 0) {
                    Toast.makeText(getApplicationContext(), "Source and destination cannot be the same", Toast.LENGTH_SHORT).show();
                    result.setText("0");
                    resultdist.setText("0");
                } else {
                    if (distance <= 1) {
                        totalfare = minfare;
                    } else if (distance > 6) {
                        totalfare = minfare + ((distance - 1) * 30);
                    } else {
                        totalfare = minfare + ((distance - 1) * 20);
                    }
                    DecimalFormat format = new DecimalFormat("#.##");
                    String fare_price = format.format(totalfare);
                    String dist = format.format(distance);
                    resultdist.setText(dist+" Km");
                    result.setText(fare_price+" Rs");
                }
            }
        });
    }

    public void displaymap(View view) {
        src = source.getText().toString();
        dest = destination.getText().toString();
        if(src.isEmpty() || dest.isEmpty()){
            Toast.makeText(getApplicationContext(), "Please enter both source and destination to proceed", Toast.LENGTH_SHORT).show();
            return;
        }
        else{
            display(src, dest);
        }
    }
    private void display(String src, String dest) {
        Uri uri = Uri.parse("https://www.google.co.in/maps/dir/" + src + "/" + dest);
        Intent intent = new Intent(Intent.ACTION_VIEW, uri);
        intent.setPackage("com.google.android.apps.maps");
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        startActivity(intent);
    }

}
